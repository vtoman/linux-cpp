#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void openFile()
{
    int fd = open("myfile.log", O_WRONLY);

    if (fd == -1)
    {
        printf("open() failed - errno = (%d)\n", errno);
        perror("ERROR: ");
    }
    else
    {
        printf("open() executed successfully\n");
    }
}

void createFile()
{
    int fd = open("myfile.log", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH);

    if (fd == -1)
    {
        printf("open() failed - errno = (%d)\n", errno);
        perror("ERROR: ");
    }
    else
    {
        printf("open() executed successfully\n");
    }
}

void createFileIfNotExisting()
{
    int fd = open("myfile.log", O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG | S_IROTH);

    if (fd == -1)
    {
        printf("open() failed - errno = (%d)\n", errno);
        perror("ERROR: ");
    }
    else
    {
        printf("open() executed successfully\n");
    }
}

void main()
{
    createFile();
    createFileIfNotExisting();
    openFile();
}