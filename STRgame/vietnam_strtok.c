#include <stdio.h>
#include <string.h>

char *strtok(char *string, char const *delim)
{
    char *pointer = NULL;
    int i = 0;
    static char *pos = NULL;

    if (string != NULL)
        pos = string;
    for (; pos[i]; i++)
    {
        int k = 0;
        for (int j = 0; !k && delim[j]; j++)
            if (delim[j] == pos[i])
                k = 1;
        if (!k && pointer == NULL)
            pointer = &pos[i];
        if (k && pointer != NULL)
            pos[i--] = '\0';
    }
    pos = &pos[i + 1];
    return pointer;
}