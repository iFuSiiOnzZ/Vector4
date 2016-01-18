#pragma once

#include <immintrin.h>

template <typename T> struct SIMDType
{
    typedef T SIMDVector;
};

template <> struct SIMDType<int>
{
    typedef __m128i SIMDVector;
};

template <> struct SIMDType<float>
{
    typedef __m128 SIMDVector;
};

template <> struct SIMDType<double>
{
    typedef __m256d SIMDVector;
};

// ADD Vector + Vector
inline SIMDType<int>::SIMDVector operator+(const SIMDType<int>::SIMDVector &V1, const SIMDType<int>::SIMDVector &V2)
{
    return _mm_add_epi32(V1, V2);
}

inline SIMDType<float>::SIMDVector operator+(const SIMDType<float>::SIMDVector &V1, const SIMDType<float>::SIMDVector &V2)
{
    return _mm_add_ps(V1, V2);
}

inline SIMDType<double>::SIMDVector operator+(const SIMDType<double>::SIMDVector &V1, const SIMDType<double>::SIMDVector &V2)
{
    return _mm256_add_pd(V1, V2);
}

// SUB Vector - Vector
inline SIMDType<int>::SIMDVector operator-(const SIMDType<int>::SIMDVector &V1, const SIMDType<int>::SIMDVector &V2)
{
    return _mm_sub_epi32(V1, V2);
}

inline SIMDType<float>::SIMDVector operator-(const SIMDType<float>::SIMDVector &V1, const SIMDType<float>::SIMDVector &V2)
{
    return _mm_sub_ps(V1, V2);
}

inline SIMDType<double>::SIMDVector operator-(const SIMDType<double>::SIMDVector &V1, const SIMDType<double>::SIMDVector &V2)
{
    return _mm256_sub_pd(V1, V2);
}

// MUL Vector * Value
inline SIMDType<int>::SIMDVector operator*(const SIMDType<int>::SIMDVector &V1, int &V2)
{
    return _mm_mul_epi32(V1, _mm_set1_epi32(V2));
}

inline SIMDType<float>::SIMDVector operator*(const SIMDType<float>::SIMDVector &V1, float &V2)
{
    return _mm_mul_ps(V1, _mm_set1_ps(V2));
}

inline SIMDType<double>::SIMDVector operator*(const SIMDType<double>::SIMDVector &V1, double &V2)
{
    return _mm256_mul_pd(V1, _mm256_set1_pd(V2));
}

// DIV Vector / Value
inline SIMDType<int>::SIMDVector operator/(const SIMDType<int>::SIMDVector &V1, int &V2)
{
    return _mm_mul_epi32(V1, _mm_set1_epi32(1 / V2));
}

inline SIMDType<float>::SIMDVector operator/(const SIMDType<float>::SIMDVector &V1, float &V2)
{
    return _mm_div_ps(V1, _mm_set1_ps(V2));
}

inline SIMDType<double>::SIMDVector operator/(const SIMDType<double>::SIMDVector &V1, double &V2)
{
    return _mm256_div_pd(V1, _mm256_set1_pd(V2));
}

