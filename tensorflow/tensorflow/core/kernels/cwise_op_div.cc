/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/kernels/cwise_ops_common.h"

namespace tensorflow {

REGISTER7(BinaryOp, CPU, "Div", functor::div, float, Eigen::half, double,
          bfloat16,posit160, complex64, complex128);
REGISTER8(BinaryOp, CPU, "Div", functor::safe_div, uint8, uint16, uint32,
          uint64, int8, int16, int32, int64);
REGISTER8(BinaryOp, CPU, "TruncateDiv", functor::safe_div, uint8, uint16,
          uint32, uint64, int8, int16, int32, int64);
REGISTER7(BinaryOp, CPU, "RealDiv", functor::div, float, Eigen::half, double,
          bfloat16, posit160, complex64, complex128);
REGISTER6(BinaryOp, CPU, "DivNoNan", functor::div_no_nan, Eigen::half, float,
          posit160, double, complex64, complex128);

#if GOOGLE_CUDA || TENSORFLOW_USE_ROCM
#if !defined(MLIR_GENERATED_GPU_KERNELS_ENABLED)
REGISTER7(BinaryOp, GPU, "Div", functor::div, float, Eigen::half, double, int16,
          int64, complex64, complex128);
REGISTER5(BinaryOp, GPU, "RealDiv", functor::div, float, Eigen::half, double,
          complex64, complex128);
REGISTER2(BinaryOp, GPU, "TruncateDiv", functor::div, int16, int64);
#endif
REGISTER2(BinaryOp, GPU, "Div", functor::div, uint8, uint16);
REGISTER2(BinaryOp, GPU, "TruncateDiv", functor::div, uint8, uint16);

#if !defined(MLIR_GENERATED_GPU_KERNELS_ENABLED) || \
    !defined(MLIR_GENERATED_EXPERIMENTAL_KERNELS_ENABLED)
REGISTER5(BinaryOp, GPU, "DivNoNan", functor::div_no_nan, Eigen::half, float,
          double, complex64, complex128);
#endif

// A special GPU kernel for int32.
// TODO(b/25387198): Also enable int32 in device memory. This kernel
// registration requires all int32 inputs and outputs to be in host memory.
REGISTER_KERNEL_BUILDER(Name("Div")
                            .Device(DEVICE_GPU)
                            .HostMemory("x")
                            .HostMemory("y")
                            .HostMemory("z")
                            .TypeConstraint<int32>("T"),
                        BinaryOp<CPUDevice, functor::safe_div<int32>>);

#endif

}  // namespace tensorflow
