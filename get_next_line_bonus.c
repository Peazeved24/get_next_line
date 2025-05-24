/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:43 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/24 16:55:55 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char buffer[4096][BUFFER_SIZE + 1];
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
        return (NULL);
    line = NULL;
    while (1)
    {
        if (buffer[fd][0] == '\0')
        {
            bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (bytes_read < 0)
                {
                    free(line);
                    return (NULL);
                }
                break;
            }
            buffer[fd][bytes_read] = '\0';
        }
        line = strjoin_line(line, buffer[fd]);
        if (!line)
            return (NULL);
        if (findnextline(buffer[fd]))
        {
            shift_buffer(buffer[fd]);
            return (line);
        }
        buffer[fd][0] = '\0';
    }
    if (line && line[0] != '\0')
        return (line);
    free(line);
    return (NULL);
}
 