/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:26:45 by badrien           #+#    #+#             */
/*   Updated: 2019/10/24 18:15:54 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i != -1)
	{
		if (str[i] == (unsigned char)c)
			return (i);
		else
			i--;
	}
	return (0);
}

int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[b] != '\0')
		b++;
	if (size == 0)
		return (b);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (b);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*ret;

	if (s2 == NULL)
		return (NULL);
	i = ft_strlen((char *)s1);
	if (!(ret = (char *)malloc(sizeof(char) * (i + ft_strlen((char*)s2) + 1))))
		return (0);
	if(s1 == NULL)
		ft_memcpy(ret, s2, ft_strlen((char*)s2) + 1);
	else
	{
		ft_memcpy(ret, s1, i);
		ft_memcpy(&ret[i], s2, ft_strlen((char*)s2) + 1);
	}
	return (ret);
}

int	ft_strlen(char *chaine)
{
	int i;

	if (chaine == NULL)
		return (0);
	i = 0;
	while (chaine[i] != '\0') //&& chaine[i] != '\n')
		i++;
	return (i);
}
