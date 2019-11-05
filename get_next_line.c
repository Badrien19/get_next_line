/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:21:22 by badrien           #+#    #+#             */
/*   Updated: 2019/11/05 14:51:49 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *line, char *rest)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	i++;
	while (line[i + j] != '\0')
		j++;
	if (!(rest = malloc(sizeof(char) * (j + 1))))
		return (0);
	j = 0;
	while (line[i + j] != '\0')
	{
		rest[j] = line[i + j];
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

char	*line_cut(char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] != '\n')
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	free(line);
	s[i] = '\0';
	return (s);
}

int		mk_line(char **rest, char **line, int fd)
{
	free(rest[fd]);
	if ((rest[fd] = get_rest(*line, rest[fd])) == NULL)
		return (-1);
	if ((*line = line_cut(*line)) == NULL)
		return (-1);
	return (1);
}

int		read_line(char **line, int fd, char *buf, char **rest)
{
	int ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		if ((*line = ft_strjoin(*line, buf)) == 0)
			return (-1);
		if (find(*line, '\n') != -1)
			return (mk_line(rest, line, fd));
	}
	if (ft_strlen(*line) == 0 && ret == 0)
		return (last_line(line));
	return (ret < 0 ? -1 : 0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];

	if (line == NULL || fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (ft_strlen(rest[fd]) != 0)
	{
		if ((*line = ft_strjoin(*line, rest[fd])) == 0)
			return (-1);
		if (find(*line, '\n') != -1)
			return (mk_line(rest, line, fd));
		free(rest[fd]);
		rest[fd] = NULL;
	}
	return (read_line(line, fd, buf, rest));
}
