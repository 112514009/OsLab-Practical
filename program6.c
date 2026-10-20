#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    printf("\n--- Creating Directory ---\n");
    if (mkdir("TestDirectory", 0755) == 0)
    printf("Directory created successfully\n");
    else
    printf("Directory may already exist\n");

    printf("\n--- Directory Contents ---\n");

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Cannot open directory\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
