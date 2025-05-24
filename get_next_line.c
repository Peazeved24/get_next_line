/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:32 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/24 16:54:49 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    line = NULL;
    while (1)
    {
        if (buffer[0] == '\0')
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (bytes_read < 0)
                {
                    free(line);
                    return (NULL);
                }
                break;
            }
            buffer[bytes_read] = '\0';
        }
        line = strjoin_line(line, buffer);
        if (!line)
            return (NULL);
        if (findnextline(buffer))
        {
            shift_buffer(buffer);
            return (line);
        }
        buffer[0] = '\0';
    }
    if (line && line[0] != '\0')
        return (line);
    free(line);
    return (NULL);
}