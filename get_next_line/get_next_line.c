/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/01 17:47:25 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //testing only
#include <stdio.h> //testing only

char	*get_next_line(int fd)
{
	static char	*line;
	char		*return_line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
	if (!line)
		line = (char *)ft_calloc(1, 1);
	else if (ft_strchr(line, '\n'))
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
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	j = ++i;
	while (line[j])
		j++;
	new_line = (char *)malloc(sizeof(char) * (j - i + 1));
	new_line[j - i] = 0;
	j = i;
	i--;
	while (line[++i])
		new_line[i - j] = line[i];
	free(line);
	return (new_line);
}

char	*ft_strdup_until_nl(char *s)
{
	char	*dest;
	int		len_s;

	len_s = 0;
	if (!s)
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
	int		b_read;

	temp = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	b_read = read(fd, temp, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(temp);
		if (!line[0])
		{
			free(line);
			line = NULL;
		}
		return (line);
	}
	while (b_read > 0)
	{
		line = ft_strjoin(line, temp);
		if (ft_strchr(line, '\n'))
			break ;
		b_read = read(fd, temp, BUFFER_SIZE);
		temp[b_read] = 0;
	}
	free(temp);
	return (line);
}

