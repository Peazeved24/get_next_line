/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:24 by peazeved          #+#    #+#             */
/*   Updated: 2025/06/20 15:46:37 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
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
