#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char data[] = "Linux System Calls Experiment\n"
    "B.Sc Cyber Security Laboratory";

    printf("\n--- Creating and Writing File ---\n");

    fd = open("student.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0)
    {
        printf("File creation failed\n");
        return 1;
    }

    write(fd, data, strlen(data));

    close(fd);

    printf("Data written successfully\n");
    return 0;
}
