/* Federico Rossi 2021
==============================================================================*/

#ifndef TENSORFLOW_CORE_PLATFORM_POSIT_POSIT_H_
#define TENSORFLOW_CORE_PLATFORM_POSIT_POSIT_H_

// clang-format off
#include "tensorflow/core/platform/byte_order.h"
//#include "positeigen.h"
#include "third_party/cppposit_private/include/positeigen.h"

// clang-format on

namespace tensorflow {
typedef posit::Posit<int16_t, 16 , 2, uint_fast16_t, posit::PositSpec::WithNan> posit16e2;
typedef posit::Posit<int8_t, 8 , 2, uint_fast8_t, posit::PositSpec::WithNan> posit8e2;
typedef posit::Posit<int32_t, 32 , 2, uint_fast32_t, posit::PositSpec::WithNan> posit32e2;

}  // end namespace tensorflow

#endif
