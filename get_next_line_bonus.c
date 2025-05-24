/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:43 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/23 18:59:27 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
    int bytes;
    static char buffer[4096][BUFFER_SIZE + 1];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    bytes = 1;
    while (buffer[fd][0] || (bytes = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
    {
        if (bytes < 0)
            return (free(line), NULL);
        line = strjoin_line(line, buffer[fd]);
        if (findnextline(buffer[fd]))
        {
            shift_buffer(buffer[fd]);
            break;
        }
        buffer[fd][0] = '\0';
    }
    if (!line)
        return NULL;
    if (line[0] == '\0')
    {
        free(line);
        return NULL;
    }
    return line;
}
