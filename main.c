#include "get_next_line.h"

int main()
{
    int fd; // fd == file descriptor do open
    char *line; // linha que vai receber o get_next_line
 
    fd = open("arquivo.txt", O_RDONLY); // 
    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd))!= NULL)
    { 
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
} 