#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char buf1[100];
    char buf2[2] = {'\n'};

    int i = 0;
    for(int i = 0; i < 99; i++)
    {
        buf1[i] = 'b';
    }

    int fd = open("log.txt", O_RDWR | O_SYNC);
    for (int i = 0; i < 5;  i++)
    {
        write(fd, buf1, 99);
        write(fd, buf2, 1);
    }

    close(fd);
}