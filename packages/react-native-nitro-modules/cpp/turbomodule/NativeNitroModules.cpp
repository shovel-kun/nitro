//
//  NativeNitroModules.cpp
//  NitroModules
//
//  Created by Marc Rousavy on 21.06.24.
//

#include "NativeNitroModules.hpp"

namespace facebook::react {

NativeNitroModules::NativeNitroModules(std::shared_ptr<CallInvoker> jsInvoker) : NativeNitroCxxSpec(jsInvoker) { }

NativeNitroModules::~NativeNitroModules() { }

jsi::Object NativeNitroModules::createTestHybridObject(jsi::Runtime &runtime) {
  return jsi::Object(runtime);
}

}