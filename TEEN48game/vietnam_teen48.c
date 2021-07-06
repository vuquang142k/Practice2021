#include "vietnam_teen48.h"

void findmax(int a[MAX_SIZE][MAX_SIZE], int j, int i, int n, int *max_c, int *max_r)
{
    int max_j = 0, max_i = 0;
    
    for (int k = 0; k < n; ++k)
        if (a[i][k] > *max_r)
        {
            max_j = k;
            *max_r = a[i][k];
        }
    for (int k = 1; k < max_j; ++k)     
        if (a[i][k])
            *max_r = 0;

    for (int k = 0; k < n; ++k)
        if (a[k][j] > *max_c)
        {
            max_i = k;
            *max_c = a[k][j];
        }
    for (int k = n; k > max_i; --k)
        if (a[k][j])
            *max_c = 0;
}

int swap(int *x, int *y)
{
    int buf = *x;
    *x = *y;
    *y = buf;
    return 1;
}

int sum(int *x, int *y)
{
    *x += *y;
    *y = 0;
    return *x;
}

char check(int move_d, int move_l, int move_r, int score_d, int score_l, int score_r)
{
    if (score_d >= score_l && (move_d || (!move_d && score_d)))
        return 'd';
    if (move_l && ((score_l > score_d && move_d) || (!move_d && !score_d)))
        return 'l';
    if ((!move_l && move_r && score_l) || (move_r == move_l && score_l >= score_r && score_l))
        return 'l';
    if(!move_d && !move_l && move_r)
        return 'r';
    return 'u';
}

char teen48game(matrix_t matrix)
{
    char swipe = 0;
    int size = matrix.rows;
    int down[MAX_SIZE][MAX_SIZE] = { 0 };
    int left[MAX_SIZE][MAX_SIZE] = { 0 };
    int right[MAX_SIZE][MAX_SIZE] = { 0 };

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            down[i][j] = matrix.matrix[i][j];
            left[i][j] = matrix.matrix[i][j];
            right[i][j] = matrix.matrix[i][j];
        }

    if (!down[size - 1][0])
    {
        int max_c = 0, max_r = 0;
        findmax(down, 0, size - 1, size, &max_c, &max_r);
        if (max_c && (max_c >= max_r))
        {
            swipe = 'd';
            return swipe;
        }
        else if (max_r && (max_r > max_c))
        {
            swipe = 'l';
            return swipe;
        }
    }

    int move_d = 0, move_l = 0, move_r = 0, score_d = 0, score_l = 0, score_r = 0;

    for (int k = 0; k < size; ++k)
    {
        for (int i = 0; i < size - 1; ++i)
            for (int j = 0; j < size; ++j)
                if (down[i][j] && !down[i + 1][j])
                    move_d = swap(&down[i][j], &down[i+1][j]);
        for (int i = 0; i < size; ++i)
            for (int j = size - 1; j; --j)
                if (left[i][j] && !left[i][j - 1])
                    move_l = swap(&left[i][j], &left[i][j-1]);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size - 1; ++j)
                if (right[i][j] && !right[i][j + 1])
                    move_r = swap(&right[i][j], &right[i][j+1]);
    }

    for (int i = size - 1; i > 0; --i)
        for (int j = 0; j < size; ++j)
            if (down[i][j] == down[i - 1][j])
                score_d += sum(&down[i][j], &down[i-1][j]);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - 1; ++j)
            if (left[i][j] == left[i][j + 1])
                score_l += sum(&left[i][j], &left[i][j+1]);
    for (int i = 0; i < size; ++i)
        for (int j = size - 1; j > 0; --j)
            if (right[i][j] == right[i][j - 1])
                score_r += sum(&right[i][j], &right[i][j-1]);
    
    swipe = check(move_d, move_l, move_r, score_d, score_l, score_r);
    return swipe;
}