#include "vietnam_7equeence.h"
#include <stdio.h>

int main(void)
{
    int successful_tests = 0;

    int array[1000] = { 0 };
    long long result1 = sequence_game(array);
    if (!result1)
        successful_tests++;
    else
        printf("Test 1 failed\n");

    for (int i = 0; i < 13; i++)
        array[i] = -1;
    long long result2 = sequence_game(array);
    if (!result2)
        successful_tests++;
    else
        printf("Test 2 failed\n");

    for (int i = 13; i < 1000; i++)
        array[1] = 1;
    long long result3 = sequence_game(array);
    if (result3 == 1)
        successful_tests++;
    else
        printf("Test 3 failed\n");

    array[0] = -2;
    for (int i = 1; i < 1000; i++)
        array[i] = -1;
    long long result4 = sequence_game(array);
    if (result4 == -1)
        successful_tests++;
    else
        printf("Test 4 failed\n");

    for (int i = 0; i < 1000; i++)
        array[i] *= -1;
    long long result5 = sequence_game(array);
    if (result5 == 2)
        successful_tests++;
    else
        printf("Test 5 failed\n");

    for (int i = 0; i < 1000; i++)
        if (i % 2)
            array[i] = 3;
        else
            array[i] = -3;
    long long result6 = sequence_game(array);
    if (result6 == 1594323)
        successful_tests++;
    else
        printf("Test 6 failed\n");

    printf("%d / 6 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}
