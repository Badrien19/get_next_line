/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:21:22 by badrien           #+#    #+#             */
/*   Updated: 2019/10/29 18:57:45 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *buf)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	while (buf[i + j] != '\0')
		j++;
	if (!(s = malloc(sizeof(char) * (j + 1))))
		return (0);
	j = 0;
	while (buf[i + j] != '\0')
	{
		s[j] = buf[i + j];
		j++;
	}
	s[j] = '\0';
	return (s);
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

int		mk_line_great_again(char **rest, char **line, int fd)
{
	if ((rest[fd] = get_rest(*line)) == NULL)
		return (-1);
	if ((*line = line_cut(*line)) == NULL)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (line == NULL || fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	*line = NULL;
	if (ft_strlen(rest[fd]) != 0)
	{
		if ((*line = ft_strjoin(*line, rest[fd])) == 0)
			return (-1);
		if (find(*line, '\n') != -1)
			return (mk_line_great_again(rest, line, fd));
		free(rest[fd]);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0
		&& !(buf[ret] = 0))
		if ((*line = ft_strjoin(*line, buf)) == 0)
			return (-1);
		else if (find(*line, '\n') != -1)
			return (mk_line_great_again(rest, line, fd));
	if (ft_strlen(*line))
		return (1);
	return (ret < 0 ? -1 : 0);
}
/*
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char **line;

	get_next_line(fd, line);
	printf("ligne 1: (%s)\n", *line);
	get_next_line(fd, line);
	printf("ligne 2: (%s)\n", *line);
	get_next_line(fd, line);
	printf("ligne 3: (%s)\n", *line);
	get_next_line(fd, line);
	printf("ligne 4: (%s)\n", *line);
	get_next_line(fd, line);
	printf("ligne 5: (%s)\n", *line);

	return (0);
} */