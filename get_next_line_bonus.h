/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:24 by peazeved          #+#    #+#             */
/*   Updated: 2025/06/03 16:51:09 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h> // read, prinf , close
# include <fcntl.h> // open
# include <stdlib.h> //malloc
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

char	*get_next_line(int fd);
int		ft_linelen(char *str);
int		ft_findnextline(char *buffer);
void	ft_shiftbuffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2);

#endif 
