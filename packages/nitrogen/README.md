<a href="https://margelo.io">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../docs/img/banner-nitrogen-dark.png" />
    <source media="(prefers-color-scheme: light)" srcset="../../docs/img/banner-nitrogen-light.png" />
    <img alt="Nitrogen" src="../../docs/img/banner-nitrogen-light.png" />
  </picture>
</a>

<br />

**Nitrogen** is a code-generator that takes TypeScript interfaces and generates C++, Swift and Kotlin code and native bindings built ontop of the [**react-native-nitro-modules**](../react-native-nitro-modules/) core APIs.

## Installation

Install [nitrogen](https://npmjs.org/nitrogen) as a `devDependency` in your react-native library:
```sh
yarn add nitrogen -D
```

## Usage

### 1. Create a react-native library

Use tools like [react-native-builder-bob](https://github.com/callstack/react-native-builder-bob) to create a react-native library.

The library must have C++ set up (on Android, a `build.gradle` with `externalNativeBuild`), TypeScript installed, and [**react-native-nitro-modules**](../react-native-nitro-modules/) installed as a dependency.

See [**react-native-nitro-image**](../react-native-nitro-image/) for an example.

### 2. Create a `nitro.json` config file

The `nitro.json` config file specifies native namespaces, library name, and other information that will be used for generating the code.

Every nitro module must have a `nitro.json` file at it's root level (i.e. the folder where `package.json` is)

```json
{
  "cxxNamespace": ["image"],
  "ios": {
    "iosModulename": "NitroImage"
  },
  "android": {
    "androidNamespace": ["image"],
    "androidCxxLibName": "NitroImage"
  }
}
```

### 3. Create a TypeScript spec

The TypeScript spec is the single source of truth. It's interfaces, enums or other type declarations will be converted to C++ (or Swift/Kotlin) types using a code generator.

```ts
export interface Image extends HybridObject<{ ios: 'c++', android: 'c++' }> {
  readonly width: number
  readonly height: number
}
```

### 4. Run `nitrogen`

Inside your library's root folder (i.e. the folder where `nitro.json` is), run nitrogen:

```sh
yarn nitrogen
```

This will generate all native files inside `./nitrogen/generated`.

### 5. Add build setup

In addition to all the C++, Swift and Kotlin files, Nitrogen also generates build setup files that you can import in your `.podspec`/`CMakeLists.txt`/`build.gradle` to automatically add all nitro-generated files to the project.

#### iOS

In your `.podspec` file, add this:

```ruby
Pod::Spec.new do |spec|
  # ...

  # Add all files generated by Nitrogen
  load 'nitrogen/generated/ios/NitroImage+autolinking.rb'
  add_nitrogen_files(spec)
end
```

#### Android

In your `build.gradle` file, add this:

```gradle
apply from: '../nitrogen/generated/android/NitroImage+autolinking.gradle'
```

And in your `CMakeLists.txt` file, add this:

```cmake
include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/NitroImage+autolinking.cmake)
```

### 6. Implement the specs

In C++:

```cpp
class HybridImage: public HybridImageSpec {
public:
  double getWidth() override { return 13; }
  double getHeight() override { return 27; }
};
```

In Swift:

```swift
class HybridImage: HybridImageSpec {
  public var hybridContext = margelo.nitro.HybridContext()
  public var memorySize: Int {
    return getSizeOf(self)
  }

  var width: Double {
    return 13
  }
  var height: Double {
    return 27
  }
}
```

In Kotlin:

```kotlin
class MathsModule: MathsModuleSpec {
  override val memorySize: ULong
    get() = 0

  override val width: Double
    get() = 13
  override val height: Double
    get() = 27
}
```