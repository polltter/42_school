//
// Created by miguel on 15-04-2023.
//

#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

int main(void)
{
    char s[1000];
    int fd1 = open("paunaminhaboca", O_RDWR | O_TRUNC | O_CREAT, 0644);
    int fd2 = open("paunaminhaboca", O_RDONLY, 0644);
    write(fd1, "oi\n", 3);
//    close(fd1);
    s[read(fd2, s, 3)] = 0;
    printf("%s\n", s);
}