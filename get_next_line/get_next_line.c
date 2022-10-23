/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:42:19 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/23 20:25:16 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //testing only
#include <stdio.h> //testing only

char	*get_next_line(int fd)
{
	static void	*temp;
	void		*line;
	size_t		bytes_read;
	size_t		size;
	size_t		total_size;

	temp = malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	size = size_until_nl(temp);
	total_size = 0;
	if (bytes_read <= 0)
		return (NULL);
	else if (size < BUFFER_SIZE || bytes_read < BUFFER_SIZE)
		return ((char *)temp);
	else
	{
		while (size == BUFFER_SIZE && bytes_read > 0)
		{
			change_size(&line, total_size, size);
			line = ft_memcpy(line + total_size, temp, size);
			bytes_read = read(fd, temp, BUFFER_SIZE);
			size = size_until_nl(temp);
			total_size += size;
		}
	}
	if (bytes_read <= 0)
	{
		free(temp);
		return (line);
	}
	else
	{
		change_size(&line, total_size, size);
		line = ft_memcpy(line + total_size, temp, size);
		free(temp);
		return (line);
	}
}

void	change_size(void **line, int old_size, int new_size)
{
	void	*temp_arr;

	if (old_size == 0)
	{
		*line = malloc(sizeof(char) * new_size);
		return ;
	}
	temp_arr = malloc(sizeof(char) * old_size);
	temp_arr = ft_memcpy(temp_arr, *line, old_size);
	free(*line);
	*line = malloc(sizeof(char) * new_size);
	*line = ft_memcpy(*line, temp_arr, old_size);
	free(temp_arr);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = -1;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (++i < n)
	{
		temp_dest[i] = temp_src[i];
	}
	return (dest);
}

size_t	size_until_nl(char *s)
{
	size_t	size;

	size = 0;
	while (size < BUFFER_SIZE - 1 && s[size] != '\n')
		size++;
	return (size);
}

int main(void)
{
	int fd = open("oi", O_RDONLY);
	char *line = get_next_line(fd);
	write(1, line, 4);
	free(line);
	close(fd);
}