/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:57:40 by peazeved          #+#    #+#             */
/*   Updated: 2025/06/20 15:43:55 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // read, prinf , close
# include <fcntl.h> // open
# include <stdlib.h> //malloc
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

char	*get_next_line(int fd);
int		ft_linelen(char *str);
int		ft_findnextline(char *buffer);
void	ft_shiftbuffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2);

#endif 