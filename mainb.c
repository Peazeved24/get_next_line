#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd1 = open("ar1.txt", O_RDONLY);
    int fd2 = open("ar2.txt", O_RDONLY);
    int fd3 = open("ar3.txt", O_RDONLY);
    char *line1;
    char *line2;
    char *line3;

    line1 = NULL;
    line2 = NULL;
    line3 = NULL;
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    // Alternando leituras entre os FDs
    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2))|| (line3 = get_next_line(fd3)))
    {
        if (line1)
        {
           printf("FD1:%s", line1);
           free(line1);
        }
        if (line2)  
        {
            printf("FD2:%s", line2);
            free(line2);
        }
        if(line3)
        {
            printf("FD3:%s", line3);
            free(line3);
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
