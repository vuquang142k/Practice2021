#include <stdio.h>
#include "vietnam_split.h"

void trasform(char **matr, char *buf, int n)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + n * i;
}

int main(void)
{
    int run = 0;

    const char str_1[] = "V a n h";
    const char str_2[] = "Quadng";
    const char str_3[] = "are";
    const char str_4[] = "the.best";
    const char str_5[] = " ";
    const char str_6[] = "";


    char d[5][5] = { 0 };
    char *matr[5];

    trasform(matr, *d, 5);


    if (split(str_1, matr, ' ') == 4 &&
            matr[0][0] == 'V' && matr[1][0] == 'a' && matr[2][0] == 'n' && matr[3][0] == 'h')
        run++;
    else
        printf("Test 1 failed\n");


    if (split(str_2, matr, 'd') == 2 &&
            matr[0][0] == 'Q' && matr[0][1] == 'u' && matr[0][2] == 'a' &&
            matr[1][0] == 'n' && matr[1][1] == 'g')
        run++;
    else
        printf("Test 2 failed\n");


    if (split(str_3, matr, ' ') == 1 &&
            matr[0][0] == 'a' && matr[0][1] == 'r' && matr[0][2] == 'e')
        run++;
    else
        printf("Test 3 failed\n");
    

    if (split(str_4, matr, '.') == 2 &&
            matr[0][0] == 't' && matr[0][1] == 'h' && matr[0][2] == 'e' && matr[0][3] == '\0' && 
            matr[1][0] == 'b' && matr[1][1] == 'e' && matr[1][2] == 's' && matr[1][3] == 't' && matr[1][4] == '\0')
        run++;
    else
        printf("Test 4 failed\n");


    if (split(str_5, matr, ' ') == 1)
        run++;
    else
        printf("Test 5 failed\n");


    if (split(str_6, matr, ' ') == 0)
        run++;
    else
        printf("Test 6 failed\n");

    printf("%d / 6 TESTS SUCCESSFUL\n", run);

    return 0;
}