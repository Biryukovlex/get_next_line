/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjoker <kjoker@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:32:57 by kjoker            #+#    #+#             */
/*   Updated: 2020/08/18 21:07:11 by kjoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*s2;

	if (!(ptr = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	s2 = ptr;
	while (*s1 != '\0')
	{
		*s2 = *s1;
		s2++;
		s1++;
	}
	*s2 = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!(new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ptr = new;
	while (*s1 != '\0')
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = '\0';
	return (ptr);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char *point;

	point = (char *)s;
	while (*point)
	{
		if (*point == (char)c)
			return (point);
		point++;
	}
	if (*point == '\0' && !c)
		return (point);
	return (NULL);
}