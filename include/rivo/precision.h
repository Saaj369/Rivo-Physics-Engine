
#ifndef RIVO_PRECISION_H
#define RIVO_PRECISION_H

#include <float.h>

namespace rivo{
    /**
     * Defines a real number precision. Rivo can be compiled in
     * single or double-precision versions. By default single precision
     * is provided.
    */
   typedef float real;
   #define real_sqrt sqrtf
   #define real_pow powf
   #define REAL_MAX FLT_MAX
}

#endif