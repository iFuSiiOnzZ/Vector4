#pragma once

#include "./SIMDTypes.h"

template <class T, class SIMDType> class CSIMDVector4
{
    public:
        union
        {
            struct { T x; T y; T z; T w; };
            SIMDType SIMDVector;
            T u[4];
        };

        CSIMDVector4(void);
        CSIMDVector4(const SIMDType &);
        CSIMDVector4(const CSIMDVector4<T, SIMDType> &);

        CSIMDVector4(T, T, T);                                                              // x, y, z
        CSIMDVector4(T, T, T, T);                                                           // x, y, z, w

        CSIMDVector4<T, SIMDType>    operator +   (const CSIMDVector4<T, SIMDType> &);      // v0 = v1 + v2
        CSIMDVector4<T, SIMDType>    operator -   (const CSIMDVector4<T, SIMDType> &);      // v0 = v1 - v2
        CSIMDVector4<T, SIMDType>    operator =   (const CSIMDVector4<T, SIMDType> &);      // v0 = v1

        CSIMDVector4<T, SIMDType>    operator *   (T);                                      // v0 = v1 * n
        CSIMDVector4<T, SIMDType>    operator /   (T);                                      // v0 = v1 / n (no zero control)

        CSIMDVector4<T, SIMDType>    operator -   (void);                                   // -v1

        T                            operator &   (const CSIMDVector4<T, SIMDType> &);      // dot   product
        CSIMDVector4<T, SIMDType>    operator ^   (const CSIMDVector4<T, SIMDType> &);      // cross product

        T                            length(void);
        CSIMDVector4<T, SIMDType>    normalize(void);
};

typedef CSIMDVector4<double, SIMDType<double>::SIMDVector> CSIMDVector4d;
typedef CSIMDVector4<float, SIMDType<float>::SIMDVector> CSIMDVector4f;
typedef CSIMDVector4<int, SIMDType<int>::SIMDVector> CSIMDVector4i;
