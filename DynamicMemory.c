#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **intArr = NULL;

    intArr = malloc(2 * sizeof(int *));

    for (int i = 0; i < 2; i++)
    {
        intArr[i] = malloc(3 * sizeof(int));
    }

    return 0;
}