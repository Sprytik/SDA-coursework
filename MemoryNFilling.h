#ifndef MEMORYNFILLING_H_INCLUDED
#define MEMORYNFILLING_H_INCLUDED

#define P 2
#define M 5
#define N 5

extern int Vector[M*N];
extern int ***Arr3D;

void CreateArray(); //функція створення динамічного тривимірного масиву.
void FreeArray(); //функція вивільнення пам’яті динамічного тривимірного масиву.
void FillArraySort(); //Заповнення динамічного тривимірного масиву впорядковано.
void FillArrayRand(); //Заповнення динамічного тривимірного масиву випадково.
void FillArrayBackSort(); //Заповнення динамічного тривимірного масиву Обернено-впорядковано.
void FillVectorSort(int n); //Заповнення вектора впорядковано.
void FillVectorRand(int n); //Заповнення вектора випадково.
void FillVectorBackSort(int n); //Заповнення вектора обернено-впорядковано.
void OutputArray(); //Вивід значень динамічного тривимірного масиву.
void OutputVector(int n); //Вивід значень вектора.

#endif // MEMORYNFILLING_H_INCLUDED
