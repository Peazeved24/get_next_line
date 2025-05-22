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

#include "get_next_line.h"

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

char	*strjoin_line(char *s1, char *s2)
{
    size_t i;
    size_t j;
    char *s3;


    i = 0;
    j = 0;

    s3 = malloc(ft_linelen(s1) + ft_linelen(s2) + 1);
    if (!s3)
        return NULL;
    while(s1 && s1[i]) // s1 pode serm null
        s3[j++] = s1[i++];
    i = 0;
    while(s2[i])
    {
        s3[j++] = s2[i];
        if(s2[i++] == '\n') // se o ultimo for \n
            break; // acaba
    }
    s3[j] = '\0';
    free(s1);
    return (s3);
}

size_t	findnextline(char *buffer)
{
	size_t	i = 0;
	size_t	j = 0;
	int		found = 0;

	while (buffer[i])
	{
		if (found)
			buffer[j++] = buffer[i];
        if (buffer[i] == '\n' && !found)
			found = 1;   
        i++;
	}
    buffer[j] = '\0';
	return (found);
}