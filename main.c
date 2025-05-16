#include <fcntl.h>    // Para open()
#include <unistd.h>   // Para read() e close()
#include <stdio.h>    // Para printf()
#include <stdlib.h>   // Para exit()

int main() {

    int fd;
    fd = open("arquivo.txt", O_RDONLY); // open ("noma do txt", FLAG)
    if(fd < 0)
    {
        perror("erro"); // msg de erro
        exit(1);
    }
    char buffer[101]; // 100 caracteres + 1 para o NULL
    ssize_t bytes = read(fd, buffer, 100); // read(fd, buffer , bytes a serem lidos)
    if(bytes < 0) // condicao de seguranca
    {
        perror("error"); // msg de erro 
        close(fd); // liberda o fd.
        exit(1); // encerra emediatamente com 1 - simbolizando erro.
    }
    buffer[bytes] = '\0';
    printf("lido :\n%s\n", buffer);
    close(fd);
    return 0;
} 
