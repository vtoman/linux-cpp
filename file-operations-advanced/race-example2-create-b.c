#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    int fd = open("example.txt", O_RDWR);
    if (fd < 0)
    {
        sleep(5);
        fd = open("example.txt", O_RDWR | O_CREAT, 0666);
        if (fd > 0)
        {
            printf("Creted example.txt");
            close(fd);
        }
    }
}