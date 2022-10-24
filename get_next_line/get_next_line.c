/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:17 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/10/24 17:28:01 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <fcntl.h> //testing only
#include <stdio.h> //testing only

char	*get_next_line(int fd)
{
	static char	*line;
	char		*return_line;

	line = read_copy(line, fd);
	return_line = ft_strdup_until_nl(line);
	line = forward_line(line);
	return (return_line);
}

char	*forward_line(char *line)
{
	while (*line && *line != '\n')
		line++;
	return (line);
}


char	*ft_strdup_until_nl(char *s)
{
	char	*dest;
	int		len_s;

	len_s = 0;
	while (s[len_s] && s[len_s] != '\n')
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

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temp[BUFFER_SIZE] = 0;
	while (read(fd, temp, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, temp);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(temp);
	return (line);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	str[len1 + len2] = 0;
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	return (str);
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


size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		printf("entrou no if\n");
		return (0);
	}
	while (s[i])
		i++;
	return (i);
}


int main(void)
{
	int fd = open("oi", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}