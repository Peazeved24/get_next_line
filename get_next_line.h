#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H


# include <fcntl.h> // para o open()
# include <stdio.h> // read , close
# include <unistd.h> // write 
# include <stdlib.h> // malloc

#ifndef BUFFER_SIZE //verifica se \ainda n foi inicializada.
# define BUFFER_SIZE 9999//inicializacao por padrao sera 9999.
#endif

int	findnextline(char *buffer);
size_t ft_linelen(char *str);
char *strjoin_line(char *s1, char *s2);
char *get_next_line(int fd);
void shift_buffer(char *buffer);
#endif