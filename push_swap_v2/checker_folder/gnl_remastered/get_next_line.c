/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:39:29 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/28 17:27:14 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE  + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;
	
	if(read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	flag = 0;
	buffer[BUFFER_SIZE] = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}