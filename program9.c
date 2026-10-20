#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    printf("Program execution started\n");
    pid = fork();
    if (pid < 0)
    {
        printf("Unable to create child process\n");
        return 1;
    }

    else if (pid == 0)
    {
        printf("\n--- Child Process ---\n");

        printf("Child Process ID : %d\n", getpid());

        printf("Parent Process ID : %d\n", getppid());
    }

    else
    {
        printf("\n--- Parent Process ---\n");

        printf("Parent Process ID : %d\n", getpid());

        printf("Child Process ID : %d\n", pid);
    }
    printf("\nProcess execution completed\n");
    return 0;
}
