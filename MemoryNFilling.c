#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MemoryNFilling.h"

int Vector[M*N];
int ***Arr3D;

void CreateArray() //функція створення динамічного тривимірного масиву.
{
    Arr3D = (int***) malloc(P*sizeof(int**));
    for (int k=0; k<P; k++)
    {
        Arr3D[k] = (int**) malloc(M*sizeof(int*));
        for (int i=0; i<M; i++)
            Arr3D[k][i] = (int*) malloc(N*sizeof(int));
    }
}

void FreeArray() //функція вивільнення пам’яті динамічного тривимірного масиву.
{
    for (int k=0; k<P; k++)
    {
        for (int i=0; i<M; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);
}

void FillArraySort() //Заповнення динамічного тривимірного масиву впорядковано.
{
    int number=0;
    for (int k=0; k<P; k++)
        for (int j=0; j<N; j++)
            for (int i=0; i<M; i++)
                Arr3D[k][i][j] = number++;
}

void FillArrayRand() //Заповнення динамічного тривимірного масиву випадково.
{
    for (int k=0; k<P; k++)
        for (int j=0; j<N; j++)
            for (int i=0; i<M; i++)
                Arr3D[k][i][j] = rand() % (P*M*N);
}

void FillArrayBackSort() //Заповнення динамічного тривимірного масиву Обернено-впорядковано.
{
    int number = P*M*N;
    for (int k=0; k<P; k++)
        for (int j=0; j<N; j++)
            for (int i=0; i<M; i++)
                Arr3D[k][i][j] = number--;
}

void FillVectorSort(int n) //Заповнення вектора впорядковано.
{
    for (int i = 0; i < n; i++)
    {
        Vector[i] = i;
    }
}

void FillVectorRand(int n) //Заповнення вектора випадково.
{
    for (int i = 0; i < n; i++)
    {
        Vector[i] = rand() % (M*N);
    }
}

void FillVectorBackSort(int n) //Заповнення вектора обернено-впорядковано.
{
    for( int i = 0; i < n; i++)
    {
        Vector[i] = M*N - 1 - i;
    }
}


void OutputArray() //Вивід значень динамічного тривимірного масиву.
{
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < P; k++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%4d", Arr3D[k][i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
}

void OutputVector(int n) //Вивід значень вектора.
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", Vector[i]);
    }
}


