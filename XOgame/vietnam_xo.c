#include <stdio.h>

int find(int arr[25], int field_size, int type)
{
    int res = -1;
    int s_col, s_row;
    int s_main_dia = 0, s_extra_dia = 0;

    for (int i = 0; i < field_size; i++)
    {
        s_col = s_row = 0;
        for (int j = 0; j < field_size; j++)
        {
            s_col += arr[i + field_size * j];
            s_row += arr[i * field_size + j];
            if (i == j)
                s_main_dia += arr[i * field_size + j];
            if (i == field_size - 1 - j)
                s_extra_dia += arr[i * field_size + j];
        }
        if (s_col == type * (field_size - 1))
            for (int str = 0; str < field_size; str++)
                if (!arr[i + str * field_size])
                    return i + str * field_size;
        if (s_row == type * (field_size - 1))
            for (int col = 0; col < field_size; col++)
                if (!arr[i * field_size + col])
                    return i * field_size + col;
    }
    if (s_main_dia == type * (field_size - 1))
        for (int i = 0; i < field_size; i++)
            if (!arr[i * field_size + i])
                return i * field_size + i;
    if (s_extra_dia == type * (field_size - 1))
        for (int i = 0; i < field_size; i++)
            if (!arr[i * field_size + (field_size - i - 1)])
                return i * field_size + (field_size - i - 1);
    return res;
}

int xogame(char **bf, const int field_size, const char symb)
{
    int arr[25];
    int my_symb = 0, anti_my = 0;
    int turn, res;

    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (bf[i][j] == symb)
                my_symb += (arr[i * field_size + j] = 1);
            else if (bf[i][j] == ' ')
                arr[i * field_size + j] = 0;
            else
                anti_my -= (arr[i * field_size + j] = -1);

    turn = (my_symb == anti_my ? 1 : 2);

    if (field_size == 3)
        if (turn == 1)
        {
            if (!anti_my)
                return 4;
            else if (anti_my == 1)
            {
                    if ((arr[5] == -1) || (arr[7] == -1))
                        return 8;
                    if ((arr[0] == -1) || arr[8] == -1)
                        return 6;
                    if ((arr[1] == -1) || (arr[3] == -1) || (arr[2] == -1) || (arr[6] == -1))
                        return 0;
                    if (arr[4] == -1)
                    {
                        if (arr[0] == 1 || arr[2] == 1)
                            return 1;
                        else if (arr[6] == 1 || arr[8] == 1)
                            return 7;
                        else if (arr[1] == 1 || arr[5] == 1)
                            return 2;
                        else if (arr[3] == 1 || arr[7] == 1)
                            return 6;
                    }
            }
            else if (anti_my == 2)
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                for (int i = 0; i < field_size; i++)
                    for (int j = 0; j < field_size; j++)
                        if (arr[i * field_size + j] == 0)
                            return i * field_size + j;
            }
            else if (anti_my == 3)
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                for (int i = 0; i < field_size; i++)
                    for (int j = 0; j < field_size; j++)
                        if (arr[i * field_size + j] == 0)
                            return i * field_size + j;
            }
            else if (anti_my == 4)
                for (int i = 0; i < 9; i++)
                    if (!arr[i])
                        return i;
        }
        else
        {
            if (anti_my == 1)
                if (arr[4] == -1)
                    return 0;
                else
                    return 4;
            else if (anti_my == 2)
            {
                if (arr[4] == -1)
                {
                    for (int i = 1; i < 8; i++)
                        if ((arr[i] == -1) && (i != 4))
                            return (8 - i);
                    return 6;
                }
                else
                {
                    res = find(arr, field_size, -1);
                    if (res >= 0)
                        return res;
                    return 1;
                }
            }
            else
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                for (int i = 0; i < 9; i++)
                    if (!arr[i])
                        return i;
            }
        }
    else
        if (turn == 1)
        {
            if (!anti_my)
                return 12;
            if (anti_my == 1)
            {
                int empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + i] == -1)
                        empty = 0;
                if (empty)
                    return 0;
                return 4;
            }
            if (anti_my == 2)
            {
                int empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + i] == -1)
                        empty = 0;
                if (empty)
                    return 24;
                empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + (field_size - i - 1)] == -1)
                        empty = 0;
                if (empty)
                    return 20;
                return 2;
            }
            if (anti_my == 3)
            {
                int empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + i] == -1)
                        empty = 0;
                if (empty)
                    return 6;
                empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + (field_size - i - 1)] == -1)
                        empty = 0;
                if (empty)
                    return 8;
                empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + 2] == -1)
                        empty = 0;
                if (empty)
                    return 7;
                return 10;
            }
            if (anti_my == 4)
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                int empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i * field_size + 2] == -1)
                        empty = 0;
                if (empty)
                    return 17;
                empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i + field_size * 2] == -1)
                        empty = 0;
                if (empty)
                    return 11;
                for (int i = 0; i < field_size*field_size; i++)
                    if (!arr[i])
                        return i;
            }
            if (anti_my == 5)
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                int empty = 1;
                for (int i = 0; i < field_size; i++)
                    if (arr[i + field_size*2] == -1)
                        empty = 0;
                if (empty)
                    return 13;
                for (int i = 0; i < field_size*field_size; i++)
                    if (!arr[i])
                        return i;
            }
            else
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                for (int i = 0; i < field_size * field_size; i++)
                    if (!arr[i])
                        return i;
            }
        }
        else
        {
            if (anti_my == 1)
            {
                if (!arr[12])
                    return 12;
                else
                    return 0;
            }
            if (anti_my == 2)
            {
                if (arr[12] == 1)
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + i] == -1)
                            empty = 0;
                    if (empty)
                        return 0;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + (field_size - i - 1)] == -1)
                            empty = 0;
                    if (empty)
                        return 4;
                    return 2;
                }
                else
                    if (!arr[4])
                        return 4;
                    else
                        return 20;
            }
            if (anti_my == 3)
            {
                if (arr[12] == 1)
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + i] == -1)
                            empty = 0;
                    if (empty)
                        return 24;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + (field_size - i - 1)] == -1)
                            empty = 0;
                    if (empty)
                        return 20;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + 2] == -1)
                            empty = 0;
                    if (empty)
                        return 7;
                    return 10;
                }
                else
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 1;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size] == -1)
                            empty = 0;
                    if (empty)
                        return 5;
                    return 21;
                }
            }
            if (anti_my == 4)
            {
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                if (arr[12] == 1)
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + i] == -1)
                            empty = 0;
                    if (empty)
                        return 6;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + (field_size - i - 1)] == -1)
                            empty = 0;
                    if (empty)
                        return 8;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size + 2] == -1)
                            empty = 0;
                    if (empty)
                        return 17;
                    empty = 1;
                    for (int i = 10; i < 15; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 11;
                }
                else
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 2;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size] == -1)
                            empty = 0;
                    if (empty)
                        return 10;
                    empty = 1;
                    for (int i = 20; i < 25; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 22;
                }
                for (int i = 0; i < field_size * field_size; i++)
                    if (arr[i] == 0)
                        return i;
            }
            if (anti_my == 5)
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;

                if (arr[12] == 1)
                {
                    int empty = 1;
                    for (int i = 10; i < 15; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 1;
                }
                else
                {
                    int empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 3;
                    empty = 1;
                    for (int i = 0; i < field_size; i++)
                        if (arr[i * field_size] == -1)
                            empty = 0;
                    if (empty)
                        return 15;
                    empty = 1;
                    for (int i = 20; i < 25; i++)
                        if (arr[i] == -1)
                            empty = 0;
                    if (empty)
                        return 23;
                }
                for (int i = 0; i < field_size * field_size; i++)
                    if (!arr[i])
                        return i;
            }
            else
            {
                res = find(arr, field_size, 1);
                if (res >= 0)
                    return res;
                res = find(arr, field_size, -1);
                if (res >= 0)
                    return res;
                for (int i = 0; i < field_size * field_size; i++)
                    if (!arr[i])
                        return i;
            }
        }
    return -1;
}
