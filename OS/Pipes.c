#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    pid_t pid;
    int fd[2];
    int n = 6;
    char string[] = "Hallo";

    int pipeStatus = pipe(fd);

    if (pipeStatus == -1)
    {
        printf("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("Forking Process went wrong");
    }
    else if (pid > 0)
    {
        printf("Im Elternprozess: \n");
        close(fd[0]);

        if ((write(fd[1], string, n)) != n)
        {
            perror("Fehler beim schreiben in die Pipe\n");
            exit(EXIT_FAILURE);
        };

        if ((waitpid(pid, NULL, 0)) != pid)
        {
            perror("Fehler beim warten auf Kindprozess");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Im Kindprozess\n");
        close(fd[1]);
        char readData[6];

        if ((read(fd[0], readData, n)) != n)
        {
            perror("Fehler beim lesen der Pipe\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("%s", readData);
            return EXIT_SUCCESS;
        }

        return EXIT_SUCCESS;
    }
    return 0;
}