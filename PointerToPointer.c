#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sort[5][30] = {
        "Zeppelin", "Auto", "Amerika", "Programmieren"};

    printf("The adress of the array is: %p\n", sort);
    printf("The adress of the first element is array is: %p\n", sort[0]);
    printf("The adress of the first element is array is: %p\n", sort[0] + 1);
    printf("The adress of the first element is array is: %p\n", sort[1]);
    printf("The adress of the first element is array is: %s\n", sort[0]);
    printf("The adress of the first element is array is: %c\n", *(sort[0] + 1));
    printf("The adress of the first element is array is: %c\n", *(sort[0] + 2));
    printf("The adress of the first element is array is: %s\n", sort[1]);

    *(sort[0]) = 'T';

    printf("%s\n", sort[0]);
}