/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/03 19:02:35 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h> //testing only
#include <stdio.h> //testing only

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*return_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
	{
		if (line[fd])
		{
			free(line[fd]);
			line[fd] = NULL;
		}
		return (NULL);
	}
	if (!line[fd])
		line[fd] = (char *)ft_calloc(1, 1);
	else if (ft_strchr(line[fd], '\n'))
	{
		return_line = ft_strdup_until_nl(line[fd]);
		line[fd] = forward_line(line[fd]);
		return (return_line);
	}
	line[fd] = read_copy(line[fd], fd);
	return_line = ft_strdup_until_nl(line[fd]);
	line[fd] = forward_line(line[fd]);
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
