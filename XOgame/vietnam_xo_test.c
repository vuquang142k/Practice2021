#include "vietnam_xo.h"
#include <stdio.h>

void trasform(char **a, char *buf, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = buf + n * i;
}

int main(void)
{
    int run3x3 = 0;

    char test_3x3[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3[i][j] = ' ';

    char *p_test_3x3[3];
    trasform(p_test_3x3, *test_3x3, 3);


    if (xogame(p_test_3x3, 3, 'X') == 4)
        run3x3++;
    else
        printf("TEST 3x3 1 FAILED\n");

    test_3x3[0][0] = 'O';
    test_3x3[2][0] = 'X';
    test_3x3[0][2] = 'O';
    test_3x3[0][1] = 'X';
    test_3x3[2][1] = 'O';
    test_3x3[1][2] = 'X';
    test_3x3[1][1] = 'X';
    test_3x3[2][2] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 3)
        run3x3++;
    else
        printf("TEST 3x3 2 FAILED\n");


    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3[i][j] = ' ';

    test_3x3[1][1] = 'X';
    test_3x3[2][0] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 0)
        run3x3++;
    else
        printf("TEST 3x3 3 FAILED\n");


    test_3x3[2][2] = 'X';
    test_3x3[0][0] = 'O';
    test_3x3[1][0] = 'X';
    test_3x3[1][2] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 1)
        run3x3++;
    else
        printf("TEST 3x3 4 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3[i][j] = ' ';

    test_3x3[1][1] = 'X';
    test_3x3[1][2] = 'O';
    test_3x3[0][0] = 'X';
    test_3x3[2][2] = 'O';
    test_3x3[0][2] = 'X';
    test_3x3[0][1] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 6)
        run3x3++;
    else
        printf("TEST 3x3 5 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3[i][j] = ' ';

    test_3x3[1][1] = 'X';
    test_3x3[0][1] = 'O';
    test_3x3[0][0] = 'X';
    test_3x3[2][1] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 8)
        run3x3++;
    else
        printf("TEST 3x3 6 FAILED\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            test_3x3[i][j] = ' ';

    test_3x3[1][1] = 'X';
    test_3x3[0][0] = 'O';
    test_3x3[2][0] = 'X';
    test_3x3[0][2] = 'O';
    test_3x3[2][2] = 'X';
    test_3x3[1][2] = 'O';
    if (xogame(p_test_3x3, 3, 'X') == 7)
        run3x3++;
    else
        printf("TEST 3x3 7 FAILED\n");


    
    int run5x5 = 0;

    char test_5x5[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    char *p_test_5x5[5];
    trasform(p_test_5x5, *test_5x5, 5);

    if (xogame(p_test_5x5, 5, 'X') == 12)
        run5x5++;
    else
        printf("TEST 5x5 1 FAILED\n");

    test_5x5[2][2] = 'X';
    test_5x5[0][0] = 'O';
    test_5x5[0][4] = 'X';
    test_5x5[1][3] = 'O';
    test_5x5[0][2] = 'X';
    test_5x5[1][2] = 'O';
    test_5x5[2][0] = 'X';
    test_5x5[2][1] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 1)
        run5x5++;
    else
        printf("TEST 5x5 2 FAILED\n");

    test_5x5[0][1] = 'X';
    test_5x5[3][0] = 'O';
    test_5x5[0][3] = 'X';
    test_5x5[3][1] = 'O';
    test_5x5[1][0] = 'X';
    test_5x5[3][2] = 'O';
    test_5x5[1][1] = 'X';
    test_5x5[3][3] = 'O';
    test_5x5[3][4] = 'X';
    test_5x5[4][0] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 9)
        run5x5++;
    else
        printf("TEST 5x5 3 FAILED\n");

    test_5x5[1][4] = 'X';
    test_5x5[4][1] = 'O';
    test_5x5[2][3] = 'X';
    test_5x5[4][2] = 'O';
    test_5x5[2][4] = 'X';
    test_5x5[4][4] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 23)
        run5x5++;
    else
        printf("TEST 5x5 4 FAILED\n");

    test_5x5[4][4] = ' ';
    test_5x5[4][2] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 24)
        run5x5++;
    else
        printf("TEST 5x5 5 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[0][2] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 0)
        run5x5++;
    else
        printf("TEST 5x5 6 FAILED\n");

    test_5x5[0][0] = 'X';
    test_5x5[1][1] = 'O';
    test_5x5[4][0] = 'X';
    test_5x5[3][1] = 'O';
    test_5x5[3][0] = 'X';
    test_5x5[2][1] = 'O';
    test_5x5[0][1] = 'X';
    test_5x5[3][0] = 'O';
    test_5x5[0][3] = 'X';
    test_5x5[3][2] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 4)
        run5x5++;
    else
        printf("TEST 5x5 7 FAILED\n");


    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[3][0] = 'O';
    test_5x5[0][0] = 'X';
    test_5x5[1][0] = 'O';
    test_5x5[1][2] = 'X';
    test_5x5[3][1] = 'O';
    test_5x5[2][1] = 'X';
    test_5x5[3][2] = 'O';
    test_5x5[0][2] = 'X';
    test_5x5[3][3] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 19)
        run5x5++;
    else
        printf("TEST 5x5 8 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[0][1] = 'O';
    test_5x5[0][0] = 'X';
    test_5x5[0][2] = 'O';
    test_5x5[4][4] = 'X';
    test_5x5[0][3] = 'O';
    test_5x5[1][1] = 'X';
    test_5x5[0][4] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 18)
        run5x5++;
    else
        printf("TEST 5x5 9 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[0][0] = 'O';
    test_5x5[0][4] = 'X';
    test_5x5[1][0] = 'O';
    test_5x5[4][0] = 'X';
    test_5x5[2][0] = 'O';
    test_5x5[1][3] = 'X';
    test_5x5[3][0] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 16)
        run5x5++;
    else
        printf("TEST 5x5 10 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[0][0] = 'O';
    test_5x5[0][4] = 'X';
    test_5x5[4][0] = 'O';
    test_5x5[0][2] = 'X';
    test_5x5[1][0] = 'O';
    test_5x5[1][2] = 'X';
    test_5x5[2][0] = 'O';
    test_5x5[3][2] = 'X';
    test_5x5[3][1] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 22)
        run5x5++;
    else
        printf("TEST 5x5 11 FAILED\n");

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            test_5x5[i][j] = ' ';

    test_5x5[2][2] = 'X';
    test_5x5[0][0] = 'O';
    test_5x5[0][4] = 'X';
    test_5x5[4][0] = 'O';
    test_5x5[0][2] = 'X';
    test_5x5[4][2] = 'O';
    if (xogame(p_test_5x5, 5, 'X') == 10)
        run5x5++;
    else
        printf("TEST 5x5 12 FAILED\n");

    printf("%d / 7 TESTS 3x3 SUCCESSFUL\n", run3x3);
    printf("%d / 12 TESTS 5x5 SUCCESSFUL\n", run5x5);
    return 0;
}