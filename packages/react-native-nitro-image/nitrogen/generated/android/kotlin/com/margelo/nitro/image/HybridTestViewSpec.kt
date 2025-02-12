///
/// HybridTestViewSpec.kt
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

package com.margelo.nitro.image

import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.*
import com.margelo.nitro.views.*

/**
 * A Kotlin class representing the TestView HybridObject.
 * Implement this abstract class to create Kotlin-based instances of TestView.
 */
@DoNotStrip
@Keep
@Suppress(
  "KotlinJniMissingFunction", "unused",
  "RedundantSuppression", "RedundantUnitReturnType", "SimpleRedundantLet",
  "LocalVariableName", "PropertyName", "PrivatePropertyName", "FunctionName"
)
abstract class HybridTestViewSpec: HybridView() {
  @DoNotStrip
  private var mHybridData: HybridData = initHybrid()

  init {
    super.updateNative(mHybridData)
  }

  override fun updateNative(hybridData: HybridData) {
    mHybridData = hybridData
    super.updateNative(hybridData)
  }

  // Properties
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var someProp: Boolean
  
  abstract var someCallback: (someParam: Double) -> Unit
  
  private var someCallback_cxx: Func_void_double
    @Keep
    @DoNotStrip
    get() {
      return Func_void_double_java(someCallback)
    }
    @Keep
    @DoNotStrip
    set(value) {
      someCallback = value
    }

  // Methods
  @DoNotStrip
  @Keep
  abstract fun someFunc(someParam: Double): Boolean

  private external fun initHybrid(): HybridData

  companion object {
    private const val TAG = "HybridTestViewSpec"
  }
}
