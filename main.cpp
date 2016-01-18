#include <cstdio>
#include <cstdlib>
#include <Windows.h>

#include "./Vector4/SIMDVector4.h"
#include "./Vector4/Vector4.h"
#include "./Vector4/SIMD4f.h"

int main(int argc, char *argv[])
{

    LARGE_INTEGER l_timeFreq;
    LARGE_INTEGER l_lastTime;
    LARGE_INTEGER l_actualTime;

    SIMD4f VS1(1.0f, 2.0f, 3.0f);
    SIMD4f VS2(1.0f, 2.0f, 3.0f);

    CVector4f V1(1.0f, 2.0f, 3.0f);
    CVector4f V2(1.0f, 2.0f, 3.0f);

    CSIMDVector4f VSV1(1.0f, 2.0f, 3.0f);
    CSIMDVector4f VSV2(1.0f, 2.0f, 3.0f);

    SIMD4f VS3;
    CVector4f V3;
    CSIMDVector4f VSV3;

    
    QueryPerformanceCounter(&l_lastTime);
    QueryPerformanceFrequency(&l_timeFreq);

    for (unsigned int i = 0; i < 9999999; i++)
    {
        VS3 = VS1 + VS2;
        VS1.x = VS1.x + 1;
        VS2.x = VS2.x + 1;
    }

    QueryPerformanceCounter(&l_actualTime);
    double l_Time = (double)(l_actualTime.QuadPart - l_lastTime.QuadPart) / ((double) l_timeFreq.QuadPart / 1000.0f);

    printf("[SIMD4f]\tTime: %lf Ms\n(%f, %f, %f)\n\n", l_Time, VS3.x, VS3.y, VS3.z);

    QueryPerformanceCounter(&l_lastTime);
    QueryPerformanceFrequency(&l_timeFreq);

    for (unsigned int i = 0; i < 9999999; i++)
    {
        V3 = V1 + V2;
        V1.x = V1.x + 1;
        V2.x = V2.x + 1;
    }

    QueryPerformanceCounter(&l_actualTime);
    l_Time = (double)(l_actualTime.QuadPart - l_lastTime.QuadPart) / ((double)l_timeFreq.QuadPart / 1000.0f);

    printf("[CVector4f]\tTime: %lf Ms\n(%f, %f, %f)\n\n", l_Time, V3.x, V3.y, V3.z);

    QueryPerformanceCounter(&l_lastTime);
    QueryPerformanceFrequency(&l_timeFreq);

    for (unsigned int i = 0; i < 9999999; i++)
    {
        VSV3 = VSV1 + VSV2;
        VSV1.x = VSV1.x + 1;
        VSV2.x = VSV2.x + 1;
    }

    QueryPerformanceCounter(&l_actualTime);
    l_Time = (double)(l_actualTime.QuadPart - l_lastTime.QuadPart) / ((double) l_timeFreq.QuadPart / 1000.0f);

    printf("[CSIMDVector4f]\tTime: %lf Ms\n(%f, %f, %f)\n\n", l_Time, VSV3.x, VSV3.y, VSV3.z);
    
   
    system("pause");
    return(EXIT_SUCCESS);
}
