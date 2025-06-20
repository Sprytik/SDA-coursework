#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Measurement.h"
#include "MemoryNFilling.h"
#include "Sort.h"
#include "Table.h"
#include "menu.h"


const int modes_number = 5;
const char menu_items[5][20] = {"1.Select6", "2.InsertExchange","3.Select3Exchange","4.Table","5.Exit"};
const int modes_sorting = 4;
const char modes_sorting_items[4][20] = {"1.BackOrdered", "2.Random", "3.Ordered", "4.Back to menu"};
void menu() //Меню вибору алгоритмів сортування для демонстрації сортування вектора та масива та перегляду повної таблиці виміру.
{
    while(1)
    {
        fflush(stdin);
        int current_mode;
        system("cls");
        printf("CourseWork by: Polishchuk Mariia KV-33\n\n");
        printf("Size P:%d M:%d N:%d\n\n", P, M, N);
        for(int i = 0; i < modes_number; i++)
        {
            printf("%s\n", menu_items[i]);
        }
        printf("\nInput modes number and press ENTER:");
        scanf("%d", &current_mode);
        switch(current_mode)
        {
        case 1:
            AllDataSelect6();
            break;

        case 2:
            AllDataInsertExchange();
            break;
        case 3:
            AllDataSelect3Exchange();
            break;
        case 4:
            system("cls");
            fflush(stdin);
            Table();
            break;
        case 5:
            system("cls");
            exit(1);
        default:
            printf("\nInvalid value entered! Please try again.");
            Sleep(2000);
            fflush(stdin);
        }
    }
}

void AllDataSelect6() //Меню вибору режиму заповнення вектора та масива для сортування алгоритмом сортування №6 методу прямого вибору. Демонстрація результатів.
{
    int select6_mode;
    while(1)
    {
        fflush(stdin);
        system("cls");
        printf("Demonstration of Select6 algorithm\n\n");
        for(int i = 0; i < modes_sorting; i++)
        {
            printf("%s\n", modes_sorting_items[i]);
        }
        printf("Input modes number and press ENTER:");
        scanf("%d", &select6_mode);
        switch(select6_mode)
        {
        case 1:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select6 algorithm on BackOrdered Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorBackSort(M*N);
            OutputVector(M*N);
            Select6_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayBackSort();
            OutputArray();
            Select6_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 2:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select6 algorithm on Random Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorRand(M*N);
            OutputVector(M*N);
            Select6_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayRand();
            OutputArray();
            Select6_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 3:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select6 algorithm on Sorted Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorSort(M*N);
            OutputVector(M*N);
            Select6_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArraySort();
            OutputArray();
            Select6_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 4:
           menu();
            break;
        default:
            printf("\nInvalid value entered! Please try again.");
            Sleep(2000);
            fflush(stdin);
        }
    }
}

void AllDataInsertExchange() //Меню вибору режиму заповнення вектора та масива для сортування гібридним алгоритом "вставка – обмін". Демонстрація результатів.
{
    int InsertExchange_mode;
    while(1)
    {
        fflush(stdin);
        system("cls");
        printf("Demonstration of InsertExchange algorithm\n\n");
        for(int i = 0; i < modes_sorting; i++)
        {
            printf("%s\n", modes_sorting_items[i]);
        }
        printf("Input modes number and press ENTER:");
        scanf("%d", &InsertExchange_mode);
        switch(InsertExchange_mode)
        {
        case 1:
            fflush(stdin);
            system("cls");
            printf("Demonstration of InsertExchange algorithm on BackOrdered Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorBackSort(M*N);
            OutputVector(M*N);
            InsertExchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayBackSort();
            OutputArray();
            InsertExchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 2:
            fflush(stdin);
            system("cls");
            printf("Demonstration of InsertExchange algorithm on Random Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorRand(M*N);
            OutputVector(M*N);
            InsertExchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayRand();
            OutputArray();
            InsertExchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 3:
            fflush(stdin);
            system("cls");
            printf("Demonstration of InsertExchange algorithm on Sorted Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorSort(M*N);
            OutputVector(M*N);
            InsertExchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArraySort();
            OutputArray();
            InsertExchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 4:
           menu();
            break;
        default:
            printf("\nInvalid value entered! Please try again.");
            Sleep(2000);
            fflush(stdin);
        }
    }
}

void AllDataSelect3Exchange() //Меню вибору режиму заповнення вектора та масива для сортування гібридним алгоритом "вибір№3 – обмін". Демонстрація результатів.
{
    int Select3Exchange_mode;
    while(1)
    {
        fflush(stdin);
        system("cls");
        printf("Demonstration of Select3Exchange algorithm\n\n");
        for(int i = 0; i < modes_sorting; i++)
        {
            printf("%s\n", modes_sorting_items[i]);
        }
        printf("Input modes number and press ENTER:");
        scanf("%d", &Select3Exchange_mode);
        switch(Select3Exchange_mode)
        {
        case 1:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select3Exchange algorithm on BackOrdered Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorBackSort(M*N);
            OutputVector(M*N);
            Select3Exchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayBackSort();
            OutputArray();
            Select3Exchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 2:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select3Exchange algorithm on Random Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorRand(M*N);
            OutputVector(M*N);
            Select3Exchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArrayRand();
            OutputArray();
            Select3Exchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 3:
            fflush(stdin);
            system("cls");
            printf("Demonstration of Select3Exchange algorithm on Sorted Array and Vector\n\n");
            printf("Size P:%d M:%d N:%d\n", P, M, N);
            printf("\nVector before sorting:\n");
            FillVectorSort(M*N);
            OutputVector(M*N);
            Select3Exchange_Vector(Vector, M*N);
            printf("\nVector after sorting:\n");
            OutputVector(M*N);
            CreateArray();
            printf("\n\nArray before sorting:\n");
            FillArraySort();
            OutputArray();
            Select3Exchange_Array(Arr3D);
            printf("\nArray after sorting:\n");
            OutputArray();
            FreeArray();
            getchar();
            break;
        case 4:
           menu();
            break;
        default:
            printf("\nInvalid value entered! Please try again.");
            Sleep(2000);
            fflush(stdin);
        }
    }
}
