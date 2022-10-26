/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/10/26 15:42:50 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //testing only
#include <stdio.h> //testing only

char	*get_next_line(int fd)
{
	static char	*line;
	char		*return_line;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		line[0] = 0;
	}
	if (ft_strchr(line, '\n'))
	{
		return_line = ft_strdup_until_nl(line);
		line = forward_line(line);
		return (return_line);
	}
	line = read_copy(line, fd);
	return_line = ft_strdup_until_nl(line);
	line = forward_line(line);
	return (return_line);
}

char	*forward_line(char *line)
{
	while (*line && *line != '\n')
		line++;
	line++;
	if (!line)
		return (0);
	return (line);
}

char	*ft_strdup_until_nl(char *s)
{
	char	*dest;
	int		len_s;

	len_s = 0;
	if (!*s)
		return (0);
	while (s[len_s] && s[len_s] != '\n')
		len_s++;
	len_s++;
	dest = (char *)malloc(sizeof(char) * len_s + 1);
	dest[len_s] = 0;
	while (--len_s >= 0)
		dest[len_s] = s[len_s];
	return (dest);
}

char	*read_copy(char *line, int fd)
{
	char	*temp;
	size_t	b_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temp[BUFFER_SIZE] = 0;
	b_read = read(fd, temp, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(temp);
		return (0);
	}
	while (b_read > 0)
	{
		line = ft_strjoin(line, temp);
		if (ft_strchr(line, '\n'))
			break ;
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read <= 0)
			return (0);
	}
	free(temp);
	return (line);
}

int main(void)
{
	int fd = open("oi", O_RDONLY);
	char	*s = get_next_line(fd);
	
	while (s)
	{

		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
}
