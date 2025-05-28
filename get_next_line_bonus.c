/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:13:16 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/28 02:15:30 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char buffer[4096][BUFFER_SIZE + 1];
    char *line;
    int bytes_read;

    bytes_read = BUFFER_SIZE;
    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    line = NULL;
    while (1)
    {
        if (buffer[fd][0] == '\0')
            bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
        buffer[fd][bytes_read] = '\0';
        if (bytes_read == 0)
            break;
        if (bytes_read < 0)
            return (free(line), NULL);
        line = strjoin_line(line, buffer[fd]);
        if (!line)
            return (NULL);
        if (findnextline(buffer[fd]))
            return (shift_buffer(buffer[fd]),line);
        buffer[fd][0] = '\0';
    }
    return (line);
}


