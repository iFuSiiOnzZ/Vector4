#pragma once

#include "./SIMDTypes.h"

class SIMD4f
{
    public:
        union
        {
            struct { float x; float y; float z; float w; };
            __m128 SIMDVector;
            float u[4];
        };

        SIMD4f(void);
        SIMD4f(const __m128 &);
        SIMD4f(const SIMD4f &);

        SIMD4f(float, float, float);               // x, y, z
        SIMD4f(float, float, float, float);        // x, y, z, w

        SIMD4f operator +   (const SIMD4f &);      // v0 = v1 + v2
        SIMD4f operator -   (const SIMD4f &);      // v0 = v1 - v2
        SIMD4f operator =   (const SIMD4f &);      // v0 = v1

        SIMD4f operator *   (float);               // v0 = v1 * n
        SIMD4f operator /   (float);               // v0 = v1 / n (no zero control)

        SIMD4f operator -   (void);                // -v1

        float  operator &   (const SIMD4f &);      // dot   product
        SIMD4f operator ^   (const SIMD4f &);      // cross product

        float  length(void);
        SIMD4f normalize(void);
};


