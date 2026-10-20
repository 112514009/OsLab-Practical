#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{

    int fd[2];

    pid_t pid;
    char message[] = "Hello from Parent Process";
    char buffer[100];

    if (pipe(fd) == -1)
    {
        printf("Pipe creation failed\n");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed\n");
        return 1;
    }

    else if (pid == 0)
    {

        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));
        printf("\nChild received message:\n");
        printf("%s\n", buffer);
        close(fd[0]);
    }

    else
    {
        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);
        printf("Parent sent message\n");
        close(fd[1]);
    }
    return 0;
}
