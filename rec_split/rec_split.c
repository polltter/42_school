/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:01:53 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/17 19:23:48 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**rec_split(char **splited, int words, char c, const char *s)
{
	char	*word;
	int		i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	word = NULL;
	if (i)
	{
		word = (char *)malloc(i + 1);
		while (*s && *s != c)
			*word++ = *s++;
		*word = 0;
	}
	if (*s == c)
		splited = rec_split(splited, words + 1, c, s);
	else if (!*s)
	{
		splited = malloc(sizeof(char *) * (words + 2));
		splited[words + 1] = 0;
	}
	splited[words] = word - i;
	return (splited);
}

char	**split(const char *s, char c)
{
	return (rec_split(0, 0, c, s));
}

int freepp(char **s)
{
	char **head = s;
	while(*s)
	{
		free(*s);
		s++;
	}
	free(head);
	return (1);
}

int	coninhas(void)
{
	return (1);
}

int	coninhas2(void *test)
{
	(void)test;
	return (1);
}

int	main(void)
{
	int i = -1;
	char *s = "  sdfklg sdfkgls sd a     ";
	char **splitted = split(s, ' ');
	int	a;

	(a = coninhas()) == 0 || (freepp(splitted) && coninhas2((void *)exit(0)));
}
