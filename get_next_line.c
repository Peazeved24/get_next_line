/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:32 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/16 17:50:24 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1]; // criar uma str static com o tamanho do meu buffer.
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0) // condicao basica de seguranca;
        return NULL;
    line = NULL;
    while(buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0) // str - primeira posicao , leitura ate a minha macro n chegar a 0!
    {
        line = strjoin_line(line, buffer);
        if (findnextline(buffer) == 1)
            break;
        if (read(fd, buffer, BUFFER_SIZE) < 0)
        {
            free(line);
            return (NULL);
        }
    }
    return (line);
}

int main(void)
{
    int fd;
    char *linha;

    // Abre o arquivo para leitura
    fd = open("arquivo.txt", O_RDONLY);
    if (fd < 0) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê e imprime cada linha até o fim do arquivo
    while ((linha = get_next_line(fd)) != NULL) {
        printf("%s", linha); // linha já contém o '\n'
        free(linha); // Libera a memória alocada por get_next_line
    }

    close(fd); // Fecha o arquivo
    return 0;
}
