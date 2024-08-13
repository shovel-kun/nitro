///
/// NitroImage-Swift-Cxx-Bridge.hpp
/// Wed Aug 14 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `Person` to properly resolve imports.
namespace margelo::nitro::image { struct Person; }

// Include C++ defined types
#include "Person.hpp"
#include <functional>
#include <optional>
#include <unordered_map>
#include <vector>

/**
 * Contains specialized versions of C++ templated types so they can be accessed from Swift,
 * as well as helper functions to interact with those C++ types from Swift.
 */
namespace margelo::nitro::image::bridge::swift {

  using Func_void_std__string = std::function<void(const std::string&)>;
  
  using std__optional_std__string_ = std::optional<std::string>;
  inline std::optional<std::string> create_std__optional_std__string_(const std::string& value) {
    return std::optional<std::string>(value);
  }
  
  using std__optional_bool_ = std::optional<bool>;
  inline std::optional<bool> create_std__optional_bool_(const bool& value) {
    return std::optional<bool>(value);
  }
  
  using std__vector_double_ = std::vector<double>;
  inline std::vector<double> create_std__vector_double_(size_t size) {
    std::vector<double> vector;
    vector.reserve(size);
    return vector;
  }
  
  using std__vector_std__string_ = std::vector<std::string>;
  inline std::vector<std::string> create_std__vector_std__string_(size_t size) {
    std::vector<std::string> vector;
    vector.reserve(size);
    return vector;
  }
  
  using std__optional_Person_ = std::optional<Person>;
  inline std::optional<Person> create_std__optional_Person_(const Person& value) {
    return std::optional<Person>(value);
  }
  
  using Func_void = std::function<void()>;
  
  using Func_std__future_double_ = std::function<std::future<double>()>;
  
  using Func_std__future_std__string_ = std::function<std::future<std::string>()>;
  
  using std__unordered_map_std__string__double_ = std::unordered_map<std::string, double>;
  inline std::unordered_map<std::string, double> create_std__unordered_map_std__string__double_(size_t size) {
    std::unordered_map<std::string, double> map;
    map.reserve(size);
    return map;
  }
  inline std::vector<std::string> get_std__unordered_map_std__string__double__keys(const std__unordered_map_std__string__double_& map) {
    std::vector<std::string> keys;
    keys.reserve(map.size());
    for (const auto& entry : map) {
      keys.push_back(entry.first);
    }
    return keys;
  }

} // namespace margelo::nitro::image::bridge::swift
