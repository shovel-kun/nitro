import type { Language } from '../../getPlatformSpecs.js'
import type { SourceFile } from '../SourceFile.js'

/**
 * Represents a TypeScript Type that can be represented in a native language (C++, Swift, Kotlin)
 */
export interface Type {
  /**
   * Get whether this type can be passed by reference in C++ (`const T&` vs `T`)
   */
  readonly canBePassedByReference: boolean
  /**
   * Get the native code required to represent this type for the given language (C++, Swift, Kotlin).
   *
   * E.g. for a `number` type, this would return `'double'` in C++.
   */
  getCode(language: Language): string
  /**
   * Get all required extra files that need to be available/imported for this type to properly work.
   *
   * E.g. for `Promise<T>`, `T` needs to be imported so it will be returned in `getExtraFiles()`.
   */
  getExtraFiles(): SourceFile[]
}

export interface NamedType extends Type {
  /**
   * Get the name of the value if it is a member or parameter.
   *
   * E.g. for a class member `double _something`, this returns `'_something'`.
   */
  readonly name: string
  /**
   * Get the name of the value escaped as a valid C++ variable name.
   *
   * E.g. for a class member `double some-value`, this returns `'some_value'`.
   */
  readonly escapedName: string
}
