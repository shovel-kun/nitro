///
/// JHybridKotlinTestObjectSpec.cpp
/// Tue Aug 20 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridKotlinTestObjectSpec.hpp"

// Forward declaration of `Car` to properly resolve imports.
namespace margelo::nitro::image { struct Car; }
// Forward declaration of `Powertrain` to properly resolve imports.
namespace margelo::nitro::image { enum class Powertrain; }
// Forward declaration of `Person` to properly resolve imports.
namespace margelo::nitro::image { struct Person; }

#include <optional>
#include <vector>
#include "Car.hpp"
#include "JCar.hpp"
#include <string>
#include "Powertrain.hpp"
#include "JPowertrain.hpp"
#include "Person.hpp"
#include "JPerson.hpp"

namespace margelo::nitro::image {

  jni::local_ref<JHybridKotlinTestObjectSpec::jhybriddata> JHybridKotlinTestObjectSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridKotlinTestObjectSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridKotlinTestObjectSpec::initHybrid),
    });
  }

  size_t JHybridKotlinTestObjectSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  double JHybridKotlinTestObjectSpec::getNumberValue() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getNumberValue");
    auto result = method(_javaPart);
    return result;
  }
  void JHybridKotlinTestObjectSpec::setNumberValue(double numberValue) {
    static const auto method = _javaPart->getClass()->getMethod<void(double /* numberValue */)>("setNumberValue");
    method(_javaPart, numberValue);
  }
  std::optional<double> JHybridKotlinTestObjectSpec::getOptionalNumber() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<jni::JDouble>()>("getOptionalNumber");
    auto result = method(_javaPart);
    return result != nullptr ? std::make_optional(result->value()) : std::nullopt;
  }
  void JHybridKotlinTestObjectSpec::setOptionalNumber(std::optional<double> optionalNumber) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JDouble> /* optionalNumber */)>("setOptionalNumber");
    method(_javaPart, optionalNumber.has_value() ? jni::JDouble::valueOf(optionalNumber.value()) : nullptr);
  }
  std::vector<double> JHybridKotlinTestObjectSpec::getPrimitiveArray() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<jni::JArrayDouble>()>("getPrimitiveArray");
    auto result = method(_javaPart);
    return [&]() {
      size_t size = result->size();
      std::vector<double> vector;
      vector.reserve(size);
      result->getRegion(0, size, vector.data());
      return vector;
    }();
  }
  void JHybridKotlinTestObjectSpec::setPrimitiveArray(const std::vector<double>& primitiveArray) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JArrayDouble> /* primitiveArray */)>("setPrimitiveArray");
    method(_javaPart, [&]() {
      size_t size = primitiveArray.size();
      jni::local_ref<jni::JArrayDouble> array = jni::JArrayDouble::newArray(size);
      array->setRegion(0, size, primitiveArray.data());
      return array;
    }());
  }
  std::vector<Car> JHybridKotlinTestObjectSpec::getCarCollection() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<jni::JArrayClass<JCar>>()>("getCarCollection");
    auto result = method(_javaPart);
    return [&]() {
      size_t size = result->size();
      std::vector<Car> vector;
      vector.reserve(size);
      for (size_t i = 0; i < size; i++) {
        auto element = result->getElement(i);
        vector.push_back(element->toCpp());
      }
      return vector;
    }();
  }
  void JHybridKotlinTestObjectSpec::setCarCollection(const std::vector<Car>& carCollection) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JArrayClass<JCar>> /* carCollection */)>("setCarCollection");
    method(_javaPart, [&]() {
      size_t size = carCollection.size();
      jni::local_ref<jni::JArrayClass<JCar>> array = jni::JArrayClass<JCar>::newArray(size);
      for (size_t i = 0; i < size; i++) {
        auto element = carCollection[i];
        array->setElement(i, *JCar::fromCpp(element));
      }
      return array;
    }());
  }

  // Methods
  

} // namespace margelo::nitro::image