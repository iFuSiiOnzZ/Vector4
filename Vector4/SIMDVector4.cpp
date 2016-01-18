#include "./SIMDVector4.h"
#include <cmath>

template <class T, class SIMDType> CSIMDVector4<T, SIMDType>::CSIMDVector4(void)
{
    u[0] = (T) 0.0;
    u[1] = (T) 0.0;
    u[2] = (T) 0.0;
    u[3] = (T) 1.0;
}

template <class T, class SIMDType> CSIMDVector4<T, SIMDType>::CSIMDVector4(T x, T y, T z)
{
    u[0] = x;
    u[1] = y;
    u[2] = z;
    u[3] = (T) 1.0;
}

template <class T, class SIMDType> CSIMDVector4<T, SIMDType>::CSIMDVector4(T x, T y, T z, T w)
{
    u[0] = x;
    u[1] = y;
    u[2] = z;
    u[3] = w;
}

template <class T, class SIMDType> CSIMDVector4<T, SIMDType>::CSIMDVector4(const SIMDType &v4)
{
    SIMDVector = v4;
}

template <class T, class SIMDType> CSIMDVector4<T, SIMDType>::CSIMDVector4(const CSIMDVector4<T, SIMDType> &v4)
{
    SIMDVector = v4.SIMDVector;
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator = (const CSIMDVector4<T, SIMDType> &v4)
{
    SIMDVector = v4.SIMDVector;
    return(*this);
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator + (const CSIMDVector4<T, SIMDType> &v4)
{
    return CSIMDVector4<T, SIMDType>(SIMDVector + v4.SIMDVector);
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator - (const CSIMDVector4<T, SIMDType> &v4)
{
    return CSIMDVector4<T, SIMDType>(SIMDVector - v4.SIMDVector);
}

template <class T, class SIMDType> inline  CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator * (T n)
{
    return CSIMDVector4<T, SIMDType>(SIMDVector * n);
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator / (T n)
{
    T l = (T)(1.0 / n);
    return CSIMDVector4<T, SIMDType>(SIMDVector * l);
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator - (void)
{
    T l_Neg = (T) -1;
    return CSIMDVector4<T, SIMDType>(SIMDVector * l_Neg);
}

template <class T, class SIMDType> inline CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::normalize(void)
{
    T l = (T)(1.0 / length());
    return(CSIMDVector4<T, SIMDType>(SIMDVector * l));
}

template <class T, class SIMDType> inline  CSIMDVector4<T, SIMDType> CSIMDVector4<T, SIMDType>::operator ^ (const CSIMDVector4<T, SIMDType> &v4)
{
    T x = u[1] * v4.u[2] - u[2] * v4.u[1];
    T y = u[2] * v4.u[0] - u[0] * v4.u[2];
    T z = u[0] * v4.u[1] - u[1] * v4.u[0];

    return(CSIMDVector4<T, SIMDType>(x, y, z));
}

template <class T, class SIMDType> inline T CSIMDVector4<T, SIMDType>::operator & (const CSIMDVector4<T, SIMDType> &v4)
{
    return(u[0] * v4.u[0] + u[1] * v4.u[1] + u[2] * v4.u[2]);
}

template <class T, class SIMDType> inline T CSIMDVector4<T, SIMDType>::length(void)
{
    return((T)std::sqrtl(u[0] * u[0] + u[1] * u[1] + u[2] * u[2] + u[3] * u[3]));
}

/* For linking */
template class CSIMDVector4<double, SIMDType<double>::SIMDVector>;
template class CSIMDVector4<float, SIMDType<float>::SIMDVector>;
template class CSIMDVector4<int, SIMDType<int>::SIMDVector>;
