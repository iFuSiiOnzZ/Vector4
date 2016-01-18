#include "./Vector4.h"
#include <cmath>

template <class T> CVector4<T>::CVector4(void)
{
    u[0] = (T) 0.0;
    u[1] = (T) 0.0;
    u[2] = (T) 0.0;
    u[3] = (T) 1.0;
}

template <class T> CVector4<T>::CVector4(T x, T y, T z)
{
    u[0] =       x;
    u[1] =       y;
    u[2] =       z;
    u[3] = (T) 1.0;
}

template <class T> CVector4<T>::CVector4(T x, T y, T z, T w)
{
    u[0] = x;
    u[1] = y;
    u[2] = z;
    u[3] = w;
}

template <class T> CVector4<T>::CVector4(const CVector4<T> &v4)
{
    u[0] = v4.u[0];
    u[1] = v4.u[1];
    u[2] = v4.u[2];
    u[3] = v4.u[3];
}

template <class T> CVector4<T> CVector4<T>::operator = (const CVector4<T> &v4)
{
    u[0] = v4.u[0];
    u[1] = v4.u[1];
    u[2] = v4.u[2];
    u[3] = v4.u[3];

    return(*this);
}

template <class T> CVector4<T> CVector4<T>::operator + (const CVector4<T> &v4)
{
    return(CVector4<T>(u[0] + v4.u[0], u[1] + v4.u[1], u[2] + v4.u[2], u[3] + v4.u[3]));
}

template <class T> CVector4<T> CVector4<T>::operator - (const CVector4<T> &v4)
{
    return(CVector4<T>(u[0] - v4.u[0], u[1] - v4.u[1], u[2] - v4.u[2], u[3] - v4.u[3]));
}

template <class T> CVector4<T> CVector4<T>::operator * (T n)
{
    return(CVector4<T>(u[0] * n, u[1] * n, u[2] * n, u[3] * n));
}

template <class T> CVector4<T> CVector4<T>::operator / (T n)
{
    T l = (T) (1.0 / n);
    return(CVector4<T>(u[0] * l, u[1] * l, u[2] * l, u[3] * l));
}

template <class T> CVector4<T> CVector4<T>::operator - (void)
{
    return(CVector4<T>(-u[0], -u[1], -u[2], -u[3]));
}

template <class T> CVector4<T> CVector4<T>::normalize(void)
{
    T l = (T) (1.0 / length());
    return(CVector4<T>(u[0] * l, u[1] * l, u[2] * l, u[3] * l));
}

template <class T> CVector4<T> CVector4<T>::operator ^ (const CVector4<T> &v4)
{
    T x = u[1] * v4.u[2] - u[2] * v4.u[1];
    T y = u[2] * v4.u[0] - u[0] * v4.u[2];
    T z = u[0] * v4.u[1] - u[1] * v4.u[0];

    return(CVector4<T>(x, y, z));
}

template <class T> T CVector4<T>::operator & (const CVector4<T> &v4)
{
    return(u[0] * v4.u[0] + u[1] * v4.u[1] + u[2] * v4.u[2]);
}

template <class T> T CVector4<T>::length(void)
{
    return((T) std::sqrtl(u[0] * u[0] + u[1] * u[1] + u[2] * u[2] + u[3] * u[3]));
}

/* For linking */
template class CVector4<double>;
template class CVector4<float>;
template class CVector4<int>;