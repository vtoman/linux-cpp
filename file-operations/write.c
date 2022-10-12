#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>


void createAndAdd()
{
    char buf[100];
    strcpy(buf, "Sample file write.\n");

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0774);
    if(fd < 0)
    {
        perror("Error occured during open");
        exit(1);
    }

    printf("Length of buf is %d\n", (int)strlen(buf));

    int sz = write(fd, buf, strlen(buf));

    printf("Bytes writen: %d\n", sz);

    close(fd);
}

void openAndAppend()
{
    char buf[100];
    strcpy(buf, "This is example of O_APPEND: Sample file write\n");

    int fd = open("output.txt", O_WRONLY | O_APPEND); // O_TRUNC
    if(fd < 0)
    {
        perror("Error occured during open");
        exit(1);
    }

    printf("Length of buf is %d\n", (int)strlen(buf));

    int sz = write(fd, buf, strlen(buf));

    printf("Bytes writen: %d\n", sz);

    close(fd);
}


int main()
{
    createAndAdd();
    openAndAppend();
}