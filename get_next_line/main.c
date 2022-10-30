/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:05:49 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/10/30 11:00:15 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("res", O_RDONLY);
	char	*s = get_next_line(fd);
	
	while (s)
	{

		printf("%s", s);
		free(s);
		//s = get_next_line(fd);
		s = NULL;
	}
	free(s);
	close(fd);
}