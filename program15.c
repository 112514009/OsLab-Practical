#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main()
{

    struct stat fileStat;

    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) == -1)
    {
        perror("Error");
        return 1;
    }

    printf("\n===== File Information =====\n");

    printf("File Size : %ld bytes\n", fileStat.st_size);

    printf("Inode Number : %ld\n", fileStat.st_ino);

    printf("Hard Links : %ld\n", fileStat.st_nlink);

    printf("Owner UID : %d\n", fileStat.st_uid);

    printf("Group GID : %d\n", fileStat.st_gid);

    printf("Owner Name : %s\n", getpwuid(fileStat.st_uid)->pw_name);

    printf("Group Name : %s\n", getgrgid(fileStat.st_gid)->gr_name);

    printf("\nPermissions : ");

    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");

    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");

    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

    printf("\n");

    printf("Last Access : %s", ctime(&fileStat.st_atime));

    printf("Last Modification : %s", ctime(&fileStat.st_mtime));

    printf("Last Status Change : %s", ctime(&fileStat.st_ctime));

    return 0;
}
