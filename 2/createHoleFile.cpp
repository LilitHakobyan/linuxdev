#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main (void)
{
    int fd = open ("file.hole", O_WRONLY|O_CREAT, 0755);
    if (fd < 0)
    {
        perror ("open() file.hole");
        exit (1);
    }

    write (fd, buf1, 10);
    lseek (fd, 1000, SEEK_CUR);
    write (fd, buf2, 10);

    close (fd);
    return 0;
}