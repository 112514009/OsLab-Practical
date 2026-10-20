#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    int bytes;
    char data[] = "Operating Systems Laboratory\n"
    "File handling using system calls\n";

    fd = open("os_notes.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd < 0)
    {
        printf("File creation failed\n");
        return 1;
    }

    bytes = write(fd, data, strlen(data));

    close(fd);

    printf("Data written successfully\n");
    printf("Bytes written : %d\n", bytes);
    return 0;
}
