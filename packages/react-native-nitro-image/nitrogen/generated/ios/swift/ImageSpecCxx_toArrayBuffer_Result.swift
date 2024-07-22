///
/// ImageSpecCxx_toArrayBuffer_Result.swift
/// Mon Jul 22 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * C++ does not support catching Swift errors yet, so we have to wrap
 * them in a Result type.
 * - .value means the function returned successfully (either a value, or void)
 * - .error means the function threw any Error. Only the message can be propagated
 */
@frozen
public enum ImageSpecCxx_toArrayBuffer_Result {
  case value(margelo.nitro.ArrayBuffer)
  case error(message: String)
}