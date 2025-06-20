#include "Measurement.h"
#include "MemoryNFilling.h"
#include "Sort.h"
#include <stdio.h>

clock_t Res[measurements_number];

float MeasurementProcessing() //Функція обробки і усереднення значень вимірів часу роботи алгоритма.
{
    long int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j=0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }
    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];
    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);
    printf("");
    return AverageValue;

}

void Select6_SortMeasurementVector(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма Select6 при сортуванні вектора.
{
    for (int i = 0; i < measurements_number; i++)
    {
        switch(sort_method)
        {
        case 1:
            FillVectorSort(M*N);
            break;
        case 2:
            FillVectorRand(M*N);
            break;
        case 3:
            FillVectorBackSort(M*N);
            break;
        }
        Res[i] = Select6_Vector(Vector, M*N);
    }
}

void InsertExchange_SortMeasurementVector(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма InsertExchange при сортуванні вектора.
{
    for (int i = 0; i < measurements_number; i++)
    {
        switch(sort_method)
        {
        case 1:
            FillVectorSort(M*N);
            break;
        case 2:
            FillVectorRand(M*N);
            break;
        case 3:
            FillVectorBackSort(M*N);
            break;
        }
        Res[i] = InsertExchange_Vector(Vector, M*N);
    }
}

void Select3Exchange_SortMeasurementVector(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма Select3Exchange при сортуванні вектора.
{
    for (int i = 0; i < measurements_number; i++)
    {
        switch(sort_method)
        {
        case 1:
            FillVectorSort(M*N);
            break;
        case 2:
            FillVectorRand(M*N);
            break;
        case 3:
            FillVectorBackSort(M*N);
            break;
        }
        Res[i] = Select3Exchange_Vector(Vector, M*N);
    }
}

void Select6_SortMeasurementArray(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма Select6 при сортуванні трьохвимірної матриці.
{
    for (int i = 0; i < measurements_number; i++)
    {
        CreateArray();
        switch(sort_method)
        {
        case 1:
            FillArraySort();
            break;
        case 2:
            FillArrayRand();
            break;
        case 3:
            FillArrayBackSort();
            break;
        }
        Res[i] = Select6_Array(Arr3D);
        FreeArray();
    }
}

void InsertExchange_SortMeasurementArray(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма InsertExchange при сортуванні трьохвимірної матриці.
{
    for (int i = 0; i < measurements_number; i++)
    {
        CreateArray();
        switch(sort_method)
        {
        case 1:
            FillArraySort();
            break;
        case 2:
            FillArrayRand();
            break;
        case 3:
            FillArrayBackSort();
            break;
        }
        Res[i] = InsertExchange_Array(Arr3D);
        FreeArray();
    }
}

void Select3Exchange_SortMeasurementArray(int sort_method) //функція яка заповнює масив Res значеннями виміру часу роботи алгоритма Select3Exchange при сортуванні вектора.
{
    for (int i = 0; i < measurements_number; i++)
    {
        CreateArray();
        switch(sort_method)
        {
        case 1:
            FillArraySort();
            break;
        case 2:
            FillArrayRand();
            break;
        case 3:
            FillArrayBackSort();
            break;
        }
        Res[i] = Select3Exchange_Array(Arr3D);
        FreeArray();
    }
}
