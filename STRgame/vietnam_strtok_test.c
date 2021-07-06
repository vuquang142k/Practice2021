#include <stdio.h>
#include "vietnam_strtok.h"

int main(void)
{
    int run = 0;
    char const delim1[] = "\n ,.!/()?";
    char const delim2[] = "";
    char const delim3[] = " ";
    char *pword;

    char str_1[] = "   Vanh..,andQuang(Vietnam)are??,\nthe\nbest!!!!";
    int first_letter[] = { 3, 10, 19, 27, 34, 38 };
    int pos_i = 0;
    
    pword = strtok(str_1, delim1);
    while (pword)
    {
        if (*pword == str_1[first_letter[pos_i]])
            run++;
        else
            printf("Test 1_%d failed\n", pos_i);
        pword = strtok(NULL, delim1);
        pos_i++;
    }
    if (run == 6)
        run = 1;
    else
    {
        printf("Test 1 failed\n");
        run = 0;
    }

    char str_2[] = "\n  .,.,,.,.,\n....\n,,,,\n?.!";
    
    pword = strtok(str_2, delim1);
    if (pword == NULL)
        run++;
    else
        printf("Test 2_0 faild\n");


    char str_3[] = "";
    
    pword = strtok(str_3, delim1);
    if (pword == NULL)
        run++;
    else
        printf("Test 3_0 faild\n");

    
    char str_4[] = "   Vanh..,andQuang(Vietnam)are??,the best!!!!";
    int pass = 0;
    pos_i = 0;
    pword = strtok(str_4, delim2);
    while (pword)
    {
        if (*pword == str_4[pos_i])
            pass++;
        else
            printf("Wrong\n");
        pword = strtok(NULL, delim2);
        pos_i ++;
    }
    if (pass == 1)
        run++;
    else
        printf("Test 4 failed\n");


    char str_5[] = "   Vanh..,andQuang(Vietnam)are??,\nthe\nbest!!!!";
    pass = 0;
    pword = strtok(str_5, delim3);
    while (pword)
    {
        if (*pword == str_5[3])
            pass++;
        else
            printf("Wrong\n");
        pword = strtok(NULL, delim3);
    }
    if (pass == 1)
        run++;
    else
        printf("Test 5 failed\n");

    printf("%d / 5 TESTS SUCCESSFUL\n", run);

    return 0;
}