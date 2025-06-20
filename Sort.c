#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>
#include "MemoryNFilling.h"

clock_t Select6_Vector(int *A, int n) //Алгоритм сортування №6 методу прямого вибору вектора за незменшенням.
{
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int s=0; s<n-1; s++)
    {
        imin=s;
        for(int i=s+1; i<n; i++)
            if (A[i]<A[imin]) imin=i;
        if (imin!=s)
        {
            tmp=A[imin];
            A[imin]=A[s];
            A[s]=tmp;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}


clock_t InsertExchange_Vector(int *A, int n) //Гібридний алгоритм "вставка – обмін" для сортування вектора за незменшенням.
{
    int j, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int i=1; i<n; i++)
    {
        j=i;
        while (j>0 && A[j]<A[j-1])
        {
            tmp=A[j];
            A[j]=A[j-1];
            A[j-1]=tmp;
            j=j-1;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select3Exchange_Vector(int *A, int n) //Гібридний алгоритм "вибір№3 – обмін" для сортування вектора за незменшенням.
{
    int Min, Max, tmp;
    int L, R;
    clock_t time_start, time_stop;
    time_start = clock();
    L=0;
    R=n-1;
    while (L<R)
    {
        if (A[L] > A[R])
        {
            tmp=A[L];
            A[L]=A[R];
            A[R]=tmp;
        }
        Min=A[L];
        Max=A[R];
        for(int i=L+1; i<R+1; i++)
        {
            if (A[i] < Min)
            {
                Min=A[i];
                A[i]=A[L];
                A[L]=Min;
            }
            else if (A[i] > Max)
            {
                Max=A[i];
                A[i]=A[R];
                A[R]=Max;
            }
        }
        L=L+1;
        R=R-1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select6_Array(int ***A) //Алгоритм №6 методу прямого вибору для сортування окремо коженого перерізу тривимірного масива наскрізно по стовпчиках за незменшенням.
{
    int imin, jmin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int dem = 0; dem <= P-1; dem++)
    {
        for(int row = 0; row <= N-1; row++)
        {
            for(int col = 0; col <= M-1; col++)
            {
                imin = row;
                jmin = col;
                for(int j = col + 1; j <= M-1; j++)
                {
                    if(A[dem][j][row] < A[dem][jmin][row])
                    {
                        jmin = j;
                    }
                }
                for(int i = row + 1; i <= N-1; i++)
                {
                    for(int j = 0; j <= M-1; j++)
                    {
                        if(A[dem][j][i] < A[dem][jmin][imin])
                        {
                            jmin = j;
                            imin = i;
                        }
                    }
                }
                if(jmin != col || imin != row)
                {
                    tmp = A[dem][jmin][imin];
                    A[dem][jmin][imin] = A[dem][col][row];
                    A[dem][col][row] = tmp;
                }
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}


clock_t InsertExchange_Array(int ***A) //Гібридний алгоритм "вставка – обмін" для сортування окремо коженого перерізу тривимірного масива наскрізно по стовпчиках за незменшенням.
{
    int j, i, prev_j, prev_i, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int dem = 0; dem <= P-1; dem++)
    {
        for(int row = 0; row <= N-1; row++)
        {
            for(int col = 0; col <= M-1; col++)
            {
                j = col;
                i = row;
                if(j != 0)
                {
                    prev_j = j - 1;
                    prev_i = i;
                }
                else
                {
                    prev_j = M-1;
                    prev_i = i - 1;
                }
                while((j > 0 || i != 0) && A[dem][j][i] < A[dem][prev_j][prev_i])
                {
                    tmp = A[dem][j][i];
                    A[dem][j][i] = A[dem][prev_j][prev_i];
                    A[dem][prev_j][prev_i] = tmp;
                    if(j != 0)
                    {
                        j--;
                    }
                    else
                    {
                        j = M-1;
                        i--;

                    }
                    if(prev_j != 0)
                    {
                        prev_j--;
                    }
                    else
                    {
                        prev_j = M-1;
                        prev_i--;
                    }
                }
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select3Exchange_Array(int ***A) //Гібридний алгоритм "вибір№3 – обмін" для сортування окремо коженого перерізу тривимірного масива наскрізно по стовпчиках за незменшенням.
{
    int Min, Max, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int dem = 0; dem <= P-1; dem++)
    {
        for(int row = 0; row <= (N/2)-1; row++)
        {
            for(int col = 0; col <= M-1; col++)
            {
                if(A[dem][col][row] > A[dem][M - 1 - col][N - 1 - row])
                {
                    tmp = A[dem][col][row];
                    A[dem][col][row] = A[dem][M - 1 - col][N - 1 - row];
                    A[dem][M - 1 - col][N - 1 - row] = tmp;
                }
                Min = A[dem][col][row];
                Max = A[dem][M - 1 - col][N - 1 - row];
                for(int i = col + 1; i <= M - 1; i++)
                {
                    if(A[dem][i][row] < Min)
                    {
                        Min = A[dem][i][row];
                        A[dem][i][row] = A[dem][col][row];
                        A[dem][col][row] = Min;
                    }
                    else if(A[dem][i][row] > Max)
                    {
                        Max = A[dem][i][row];
                        A[dem][i][row] = A[dem][M - 1 - col][N - 1 - row];
                        A[dem][M - 1 - col][N - 1 - row] = Max;
                    }
                }
                for(int i = row + 1; i < N - 1 - row; i++)
                {
                    for(int j = 0; j <= M - 1; j++)
                    {
                        if(A[dem][j][i] < Min)
                        {
                            Min = A[dem][j][i];
                            A[dem][j][i] = A[dem][col][row];
                            A[dem][col][row] = Min;
                        }
                        else if(A[dem][j][i] > Max)
                        {
                            Max = A[dem][j][i];
                            A[dem][j][i] = A[dem][M - 1 - col][N - 1 - row];
                            A[dem][M - 1 - col][N - 1 - row] = Max;
                        }
                    }
                }
                for(int i = col + 1; i <= M - 1; i++)
                {
                    if(A[dem][M - 1 - i][N - 1 - row] < Min)
                    {
                        Min = A[dem][M - 1 - i][N - 1 - row];
                        A[dem][M - 1 - i][N - 1 - row] = A[dem][col][row];
                        A[dem][col][row] = Min;
                    }
                    if(A[dem][M - 1 - i][N - 1 - row] > Max)
                    {
                        Max = A[dem][M - 1 - i][N - 1 - row];
                        A[dem][M - 1 - i][N - 1 - row] = A[dem][M - 1 - col][N - 1 - row];
                        A[dem][M - 1 - col][N - 1 - row] = Max;
                    }
                }
            }
        }
        for(int col = 0; col <= (M-1)/2; col++)
        {
            if(A[dem][col][(N-1)/2] > A[dem][M - 1 - col][(N-1)/2])
            {
                tmp = A[dem][col][(N-1)/2];
                A[dem][col][(N-1)/2] = A[dem][M - 1 - col][(N-1)/2];
                A[dem][M - 1 - col][(N-1)/2] = tmp;
            }
            Min = A[dem][col][(N-1)/2];
            Max = A[dem][M - 1 - col][(N-1)/2];
            for(int i = col + 1; i <= M - 1 - col; i++)
            {
                if(A[dem][i][(N-1)/2] < Min)
                {
                    Min = A[dem][i][(N-1)/2];
                    A[dem][i][(N-1)/2] = A[dem][col][(N-1)/2];
                    A[dem][col][(N-1)/2] = Min;
                }
                else if(A[dem][i][(N-1)/2] > Max)
                {
                    Max = A[dem][i][(N-1)/2];
                    A[dem][i][(N-1)/2] = A[dem][M - 1 - col][(N-1)/2];
                    A[dem][M - 1 - col][(N-1)/2] = Max;
                }
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

