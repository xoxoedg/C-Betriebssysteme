#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char content[255] = {};
    char strings[3][255];
    FILE *file = fopen("test.txt", "r");
    FILE *file2 = fopen("brumm.txt", "w+");

    if (file == NULL)
    {
        printf("Couldnt open the file");
    }

    if (file2 == NULL)
    {
        printf("Couldnt open file 2");
    }

    int counter = 0;

    while (!feof(file))
    {

        fgets(content, 20, file);
        fprintf(file2, "%s", content);
        counter++;
    }
    printf("The counter is: %d \n", counter);

    fprintf(file2, "Hello im wow");
    fprintf(file2, "\n");
    fprintf(file2, "Brumm brumm");
}
