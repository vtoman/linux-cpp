#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
    char buf[20] = {0};
    int fd = open("input.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error: ");
        exit(1);
    }

    int sz = read(fd, buf, 10);
    printf("read fd = %d, %d bytes were read.\n", fd, sz);
    buf[sz] = '\0';
    printf("Bytes: %s\n", buf);

    // reads are successive

    sz = read(fd, buf, 10);
    printf("read fd = %d, %d bytes were read.\n", fd, sz);
    buf[sz] = '\0';
    printf("Bytes: %s\n", buf);

    // no more to read

    sz = read(fd, buf, 10);
    printf("read fd = %d, %d bytes were read.\n", fd, sz);
    buf[sz] = '\0';
    printf("Bytes: %s\n", buf);
}