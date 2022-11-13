/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:11:46 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/11/13 15:02:45 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	word_count(char *s)
{
	int	i;
	int	words;

	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] != ' ')
		{
			words++;
			while (s[i] != ' ' && s[i + 1])
				i++;
		}
	}
	return (words);
}

char	*populate(char *s, int i, int j)
{
	char	*word;

	if (s[i + j] == ' ' || !s[i + j])
	{
		word = malloc(sizeof(char) * (j + 1));
		word[j] = 0;
	}
	else
	{
		word = populate(s, i, j + 1);
		word[j] = s[i + j];
	}
	return (word);
}

char	**split(char *s)
{
	int		n_words;
	char	**words;
	int		i;
	int		w;

	n_words = word_count(s);
	words = malloc(sizeof(char *) * (n_words + 1));
	if (!words)
		return (NULL);
	words[n_words] = 0;
	i = -1;
	w = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			words[++w] = populate(s, i, 0);
		while (s[i] != ' ' && s[i + 1])
			i++;
	}
	return (words);
}
