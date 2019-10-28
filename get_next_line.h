/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:24:24 by badrien           #+#    #+#             */
/*   Updated: 2019/10/28 10:40:10 by badrien          ###   ########.fr       */
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

int		find(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen(char *chaine);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_free_join(char *str, char *str2);
char	*get_new_line(int fd, char **line);
int		get_next_line(int fd, char **line);
int		mk_line_great_again
			(char **rest, char **line, char buf[BUFFER_SIZE + 1]);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
