/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:49 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/24 16:55:09 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:41 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/24 16:50:21 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:49 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/22 18:44:21 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_linelen(char *str) // ft exclusiva para leitura de txt.
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i + 1);   
        i++;
    }     
    return(i);
}
char *strjoin_line(char *s1, char *s2)
{
    size_t i = 0, j = 0;
    size_t len1 = 0;
    size_t len2 = 0;
    char *s3;

    if (s1)
        while (s1[len1])
            len1++;
    while (s2[len2] && s2[len2] != '\n')
        len2++;
    if (s2[len2] == '\n')
        len2++;
    s3 = malloc(len1 + len2 + 1);
    if (!s3)
        return (NULL);
    for (i = 0; i < len1; i++)
        s3[j++] = s1[i];
    for (i = 0; i < len2; i++)
        s3[j++] = s2[i];
    s3[j] = '\0';
    free(s1);
    return (s3);
}

int	findnextline(char *buffer)
{
	size_t	i = 0;

	while (buffer[i])
	{
        if (buffer[i] == '\n')
			return 1;   
        i++;
	}
	return 0;
}

void shift_buffer(char *buffer)
{
    size_t i = 0;
    size_t j = 0;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    while (j < BUFFER_SIZE)
        buffer[j++] = '\0';
}