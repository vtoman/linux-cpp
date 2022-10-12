#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void createFile()
{
    int fd = open("seek.txt", O_RDWR | O_CREAT | O_TRUNC, 0774);
    if (fd < 0)
    {
        perror("Error occured during open");
        exit(1);
    }

    char buf[100] = {0};
    strcpy(buf, "0123456789");

    int sz = write(fd, buf, strlen(buf));

    printf("Bytes written: %d\n", sz);

    close(fd);
}

void seekFile()
{
    int fd = open("seek.txt", O_RDWR);
    if (fd < 0)
    {
        perror("Error occured during open");
        exit(1);
    }

    int seek_pos = lseek(fd, 0, SEEK_SET);
    printf("Offset positon: %d\n", seek_pos);

    seek_pos = lseek(fd, 2, SEEK_SET);
    printf("Offset positon: %d\n", seek_pos);

    seek_pos = lseek(fd, 6, SEEK_CUR);
    printf("Offset positon: %d\n", seek_pos);

    char buf[100];
    int sz = read(fd, buf, 10);
    buf[sz] = '\0';
    printf("Bytes read: (%d) %s\n", sz, buf);

    seek_pos = lseek(fd, 0, SEEK_END);
    printf("Offset positon: %d\n", seek_pos);
    
    strcpy(buf, "-0123456789\n");
    sz = write(fd, buf, strlen(buf));

    close(fd);
}

int main()
{
    createFile();
    seekFile();
}