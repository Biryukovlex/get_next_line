/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjoker <kjoker@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:56:03 by kjoker            #+#    #+#             */
/*   Updated: 2020/08/18 23:36:43 by kjoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i] == '\0' && src[i] != '\0')
	{
		return (0);
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*check_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			while (*remainder)
				*remainder++ = '\0';
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	static char		*remainder;
	char 			buf[BUFFER_SIZE + 1];
	int 			byte_was_read;
	char 			*p_n;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);	
	p_n = check_remainder(remainder, line);
	while(!p_n && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{	
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
		return ((byte_was_read || ft_strlen(remainder) || ft_strlen(*line)) ? 1 : 0);
}

int	main(void)
{
	char	*line;
	int		cycle;
	int 	fd;

	fd = open("dialogues.txt", O_RDONLY);
	while ((cycle = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
	}
	return (0);
}