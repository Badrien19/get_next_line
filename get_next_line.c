/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:21:22 by badrien           #+#    #+#             */
/*   Updated: 2019/10/24 18:30:25 by badrien          ###   ########.fr       */
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
	printf("S = %s\n", s);
	return(s);
}

int get_next_line(int fd, char **line)
{
	static char *rest;
	char buf[BUFFER_SIZE + 1];
	int ret;

	// rest au debut de line puis couper la line
	// et si plusieurs \n je strndup a partir du premier \n pour le 'rest'

	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if(find(*line, '\n') != 0)
		{
			rest = get_rest(buf);
			*line = line_cut(*line);
			break;
		}
	}
	printf("line = %s\n\n", *line);
	printf("rest = %s\n\n", rest);
	return (0);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char **line;

	get_next_line(fd, line);

	return (0);
}