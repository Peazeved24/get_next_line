/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:13:16 by peazeved          #+#    #+#             */
/*   Updated: 2025/06/03 18:59:20 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer[fd][0] == '\0')
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free(line), NULL);
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		while (ft_findnextline(buffer[fd]))
			return (ft_shiftbuffer(buffer[fd]), line);
	}
	return (line);
}

/*int main()
{
	int fd1;
    int fd2;
    int fd3;
	char *line1;
	char *line2;
	char *line3;
	fd1 = open("t1.txt", O_RDONLY);
    fd2 = open("t2.txt", O_RDONLY);
    fd3 = open("t3.txt", O_RDONLY);
	if(fd1 < 0 || fd2 <0 || fd3 < 0)
		return (-1);
	line1 = NULL ;
    line2 = NULL;
    line3 = NULL;
    
    while ((line1 = get_next_line(fd1)) ||
    (line2 = get_next_line(fd2))|| (line3 = get_next_line(fd3)))
	{
        if(line1)
        {
            printf("FD1:%s", line1);
            free(line1);
        }
        if(line2)
        {
            printf("FD2:%s", line2);
            free(line2);
        }
        if(line3)
        {
            printf("FD3:%s", line3);
            free(line3);
        }
	}
	close(fd1);
    close(fd2);
    close(fd3);
	return 0;
}*/