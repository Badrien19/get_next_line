/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:24:24 by badrien           #+#    #+#             */
/*   Updated: 2019/11/05 14:51:57 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

int		find(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *chaine);
char	*get_rest(char *line, char *rest);
char	*line_cut(char *line);
int		last_line(char **line);
int		get_next_line(int fd, char **line);
int		mk_line(char **rest, char **line, int fd);
int		read_line(char **line, int fd, char *buf, char **rest);

#endif
