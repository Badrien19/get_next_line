/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:21:22 by badrien           #+#    #+#             */
/*   Updated: 2019/10/25 17:25:41 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_rest(char *buf)
{
	int i;
	int j;
	char *s;

	i = 0;
	j = 0;
	while(buf[i] != '\n')
		i++;
	i++;
	while(buf[i + j] != '\0')
		j++;
	s = malloc(sizeof(char) * (j + 1)); // a protger
	j = 0;
	while(buf[i + j] != '\0')
	{
		s[j] = buf[i + j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
char *line_cut(char *line)
{
	int i;
	char *s;

	i = 0; 
	while (line[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return(s);
}

/*
**	1 : A line has been read
**	0 : Did not read anything
**	-1 : An error happened
*/

int get_next_line(int fd, char **line)
{
	static char *rest[OPEN_MAX];
	char buf[BUFFER_SIZE + 1];
	int ret;

	if(line == NULL || fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 0)
		return (-1);

	*line = NULL;

	if(rest[fd] != NULL)
	{
		if(ft_strlen(rest[fd]) != 0)
		{
			free(*line);
			*line = ft_strjoin(*line, rest[fd]);
			if(find(*line, '\n') != -1) // on trouve un /n
			{
				rest[fd] = get_rest(*line);
				*line = line_cut(*line);
				return (1);
			}
		}
	}
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if(find(*line, '\n') != -1)
		{
			rest[fd] = get_rest(buf);
			*line = line_cut(*line);
			return(1);
		}
	}
	if(ft_strlen(*line))
		return (1);
	return (ret < 0 ? -1 : 0);
}