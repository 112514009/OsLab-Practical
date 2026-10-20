#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    int bytes;

    printf("\n--- Reading File Content ---\n");

    fd = open("student.txt", O_RDONLY);

    if (fd < 0)
    {
        printf("File opening failed\n");
        return 1;
    }

    bytes = read(fd, buffer, sizeof(buffer) - 1);

    buffer[bytes] = '\0';

    printf("%s\n", buffer);

    close(fd);
    return 0;
}
