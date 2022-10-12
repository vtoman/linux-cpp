#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

int main()
{
    char buf[100] = {0};
    strcpy(buf, "This is message to be written\n");

    int sz = write(STDOUT_FILENO, buf, strlen(buf));    
}