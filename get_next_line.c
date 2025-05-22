/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:32 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/22 18:54:46 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
    int bytes;
    static char buffer[BUFFER_SIZE + 1]; // criar uma str static com o tamanho do meu buffer. --permite a leitura de onde parei
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0) // condicao basica de seguranca;
        return (NULL);
    line = (NULL); // incio da construcao da linha,
    bytes = 1;
    while(buffer[0] || (bytes = read(fd, buffer, BUFFER_SIZE)) > 0) // str - primeira posicao , leitura ate a minha macro n chegar a 0!
    {
        if(bytes < 0)
            return(free(line), NULL);
        line = strjoin_line(line, buffer);
        if (findnextline(buffer) == 1)
            break;
    }
    if(!line || line[0] == '\0')
        return NULL;
    return (line);
}