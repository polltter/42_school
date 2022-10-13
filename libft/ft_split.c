/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:17:15 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/11 17:10:16 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *s, char c)
{
	int	words;
	int	i;

	i = -1;
	words = 0;
	while (++i < (int)ft_strlen(s))
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] != 0)
		{
			if (s[i + 1] == c || s[i + 1] == 0)
			{
				words++;
				break ;
			}
			i++;
		}
	}
	return (words);
}

char	**allocate_mem(char **s, char c, const char *str)
{
	int	i;
	int	counter;
	int	word;

	word = 0;
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		while (str[i] == c && str[i])
			i++;
		counter = 0;
		while (str[i] != c && str[i] != 0)
		{
			counter++;
			if (str[i + 1] == c || str[i + 1] == 0)
			{
				s[word] = (char *)malloc(sizeof(char) * (counter + 1));
				s[word][counter] = 0;
				word++;
				break ;
			}
			i++;
		}
	}
	return (s);
}

char	**write_mem(char **s, char c, const char *str)
{
	int	i;
	int	counter;
	int	word;

	word = 0;
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		while (str[i] == c && str[i])
			i++;
		counter = 0;
		while (str[i] != c && str[i] != 0)
		{
			s[word][counter] = str[i];
			counter++;
			if (str[i + 1] == c || str[i + 1] == 0)
			{
				word++;
				break ;
			}
			i++;
		}
	}
	return (s);
}

char	**ft_slipt(char const *s, char c)
{
	int		nbr_words;
	char	**splited;

	nbr_words = word_counter(s, c);
	splited = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!splited)
		return (NULL);
	splited[nbr_words] = NULL;
	splited = allocate_mem(splited, c, s);
	splited = write_mem(splited, c, s);
	return( splited);
}
