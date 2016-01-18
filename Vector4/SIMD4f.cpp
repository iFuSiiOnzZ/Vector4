#include "./SIMD4f.h"
#include <cmath>

SIMD4f::SIMD4f(void)
{
    u[0] = (float) 0.0;
    u[1] = (float) 0.0;
    u[2] = (float) 0.0;
    u[3] = (float) 1.0;
}

SIMD4f::SIMD4f(float x, float y, float z)
{
    u[0] = x;
    u[1] = y;
    u[2] = z;
    u[3] = (float) 1.0;
}

SIMD4f::SIMD4f(float x, float y, float z, float w)
{
    u[0] = x;
    u[1] = y;
    u[2] = z;
    u[3] = w;
}

SIMD4f::SIMD4f(const SIMD4f &v4)
{
    SIMDVector = v4.SIMDVector;
}

SIMD4f::SIMD4f(const __m128 &v4)
{
    SIMDVector = v4;
}

SIMD4f SIMD4f::operator = (const SIMD4f &v4)
{
    SIMDVector = v4.SIMDVector;
    return(*this);
}

SIMD4f SIMD4f::operator + (const SIMD4f &v4)
{
    return SIMD4f(_mm_add_ps(SIMDVector, v4.SIMDVector));
}

SIMD4f SIMD4f::operator - (const SIMD4f &v4)
{
    return SIMD4f(_mm_sub_ps(SIMDVector, v4.SIMDVector));
}

SIMD4f SIMD4f::operator * (float n)
{
    return SIMD4f(_mm_mul_ps(SIMDVector, _mm_set1_ps(n)));
}

SIMD4f SIMD4f::operator / (float n)
{
    float l = (float)(1.0 / n);
    return SIMD4f(_mm_mul_ps(SIMDVector, _mm_set1_ps(l)));
}

SIMD4f SIMD4f::operator - (void)
{
    return SIMD4f(_mm_mul_ps(SIMDVector, _mm_set1_ps((float) -1)));
}

SIMD4f SIMD4f::normalize(void)
{
    float l = (float)(1.0 / length()); 
    return(SIMD4f(_mm_mul_ps(SIMDVector, _mm_set1_ps(l))));
}

SIMD4f SIMD4f::operator ^ (const SIMD4f &v4)
{
    __m128 l_SIMDVector = _mm_sub_ps
    (
        _mm_mul_ps(_mm_shuffle_ps(SIMDVector, SIMDVector, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(v4.SIMDVector, v4.SIMDVector, _MM_SHUFFLE(3, 1, 0, 2))), 
        _mm_mul_ps(_mm_shuffle_ps(SIMDVector, SIMDVector, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(v4.SIMDVector, v4.SIMDVector, _MM_SHUFFLE(3, 0, 2, 1)))
    );

    return(SIMD4f(l_SIMDVector));
}

float SIMD4f::operator & (const SIMD4f &v4)
{
    return(u[0] * v4.u[0] + u[1] * v4.u[1] + u[2] * v4.u[2]);
}

float SIMD4f::length(void)
{
    return((float)std::sqrtl(u[0] * u[0] + u[1] * u[1] + u[2] * u[2] + u[3] * u[3]));
}

