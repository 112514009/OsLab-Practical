#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat fileInfo;

    printf("\n--- File Information ---\n");

    if (stat("student.txt", &fileInfo) == 0)
    {

        printf("File Size       : %ld bytes\n", (long)fileInfo.st_size);

        printf("Number of Links : %ld\n", (long)fileInfo.st_nlink);

        printf("Permissions     : %o\n", fileInfo.st_mode & 0777);
    }
    else
    {
        printf("Unable to get file information\n");
    }

    return 0;
}
