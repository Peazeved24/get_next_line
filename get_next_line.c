/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:32 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/15 17:10:21 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE]; // criar uma str static com o tamanho do meu buffer.
    char *line;

    if(fd <= 0 || BUFFER_SIZE <= 0) // condicao basica de seguranca;
        return NULL;
    line = NULL;
    while(buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0) // str - primeira posicao , leitutra ate a minha macro n chegar a 0!
    {

    }
}