#pragma once

template <class T> class CVector4
{
    public:
        union
        {
            struct { T x; T y; T z; T w; };
            T u[4];
        };

        CVector4           (void);
        CVector4           (const CVector4<T> &);

        CVector4           (T, T, T);                               // x, y, z
        CVector4           (T, T, T, T);                            // x, y, z, w

        CVector4<T>        operator +   (const CVector4<T> &);      // v0 = v1 + v2
        CVector4<T>        operator -   (const CVector4<T> &);      // v0 = v1 - v2
        CVector4<T>        operator =   (const CVector4<T> &);      // v0 = v1

        CVector4<T>        operator *   (T);                        // v0 = v1 * n
        CVector4<T>        operator /   (T);                        // v0 = v1 / n (no zero control)

        CVector4<T>        operator -   (void);                     // -v1

        T                  operator &   (const CVector4<T> &);      // dot   product
        CVector4<T>        operator ^   (const CVector4<T> &);      // cross product

        T                  length       (void);
        CVector4<T>        normalize    (void);
};

typedef CVector4<double> CVector4d;
typedef CVector4<float> CVector4f;
typedef CVector4<int> CVector4i;
