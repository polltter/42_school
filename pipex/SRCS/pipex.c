/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/12 20:15:57 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**paths;

	if (ac > 3)
	{
		paths = split(find_path_var(env), ':');
	}

}
