/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:50:39 by peazeved          #+#    #+#             */
/*   Updated: 2025/05/22 18:10:37 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <fcntl.h> // para o open()
# include <stdio.h> // read , close
# include <unistd.h> // write 
# include <stdlib.h> // malloc

#ifndef BUFFER_SIZE //verifica se \ainda n foi inicializada.
# define BUFFER_SIZE 9999// inicializacao por padrao sera 9999.
#endif


size_t ft_linelen(char *str);
char	*strjoin_line(char *s1, char *s2);
size_t	findnextline(char *buffer);
char *get_next_line(int fd);
#endif