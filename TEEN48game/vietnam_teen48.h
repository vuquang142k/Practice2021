#ifndef _VIETNAM_TEEN48_H_
#define _VIETNAM_TEEN48_H_

#include<stdio.h>
#define MAX_SIZE 6

typedef struct
{
    int rows;
    int columns;
    int **matrix;
} matrix_t;

char teen48game(matrix_t matrix);

#endif