#include "vietnam_teen48.h"
#include <stdio.h>

void trasform(int **a, int *buf, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = buf + n * i;
}

int main(void)
{
    int run = 0;
    matrix_t matr;
    matr.rows = 4;
    matr.columns = 4;
    int *d[6];

    int a1[4][4] = {{0,0,0,0},
                   {8,4,2,16},
                   {4,8,4,2},
                   {0,0,16,0}};

    trasform(d, *a1, 4);
    matr.matrix = d;
    if (teen48game(matr) == 'l')
        run++;
    else
        printf("Test 1 failed\n");

    int a2[4][4] = {{2,2,2,2},
                   {2,2,2,2},
                   {2,2,2,2},
                   {2,2,2,2}};

    trasform(d, *a2, 4);
    matr.matrix = d;
    if (teen48game(matr) == 'd')
        run++;
    else
        printf("Test 2 failed\n");

    int a3[4][4] = {{0,0,0,0},
                   {8,4,2,16},
                   {0,8,4,2},
                   {0,4,8,0}};

    trasform(d, *a3, 4);
    matr.matrix = d;
    if (teen48game(matr) == 'd')
        run++;
    else
        printf("Test 3 failed\n");


    int a4[4][4] = {{0,0,2,2},
                   {0,2,2,2},
                   {0,0,2,2},
                   {8,2,0,2}};

    trasform(d, *a4, 4);
    matr.matrix = d;
    if (teen48game(matr) == 'd')
        run++;
    else
        printf("Test 4 failed\n");

    matr.rows = 6;
    matr.columns = 6;
    int a5[6][6] = {{0,0,0,0,0,0},
                    {2,2,2,2,2,2},
                    {4,4,4,4,4,4},
                    {8,8,8,8,8,8},
                    {32,32,32,32,32,32},
                    {64,64,64,64,64,64}};
    trasform(d, *a5, 6);
    matr.matrix = d;
    if (teen48game(matr) == 'l')
        run++;
    else
        printf("Test 5 failed\n");


    int a6[6][6] = {{2,2,2,2,2,2},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,2},
                    {0,0,0,0,0,16},
                    {0,0,8,2,2,16}};

    trasform(d, *a6, 6);
    matr.matrix = d;
    if (teen48game(matr) == 'd')
        run++;
    else
        printf("Test 6 failed\n");


    int a7[6][6] = {{0,2,0,0,0,0}, 
                    {2,0,0,0,0,0},
                    {0,0,2,4,2,0},
                    {0,0,4,8,16,32},
                    {0,0,8,16,32,64},
                    {0,0,16,32,64,128}};
    trasform(d, *a7, 6);
    matr.matrix = d;
    if (teen48game(matr) == 'd')
        run++;
    else
        printf("Test 7 failed\n");


    int a8[6][6] = {{0,0,2,4,8,16},
                    {0,2,4,8,16,32},
                    {2,4,8,16,32,64},
                    {4,8,16,32,64,128},
                    {8,16,32,64,128,256},
                    {16,32,64,128,256,512}};
    trasform(d, *a8, 6);
    matr.matrix = d;
    if (teen48game(matr) == 'l')
        run++;
    else
        printf("Test 8 failed\n");

    printf("%d / 8 TESTS SUCCESSFUL\n", run);
    return 0;
}
