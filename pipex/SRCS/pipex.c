/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 09:57:32 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**paths;
	void	*cmds;

	if (ac > 3)
	{
		cmds = creat_array();
		paths = split(find_path_var(env), ':');
		find_cmds(paths, av + 1, cmds);
		t_elems *temp = array(cmds)->begin;
		while (temp)
		{
			ft_printf("%s\n", (char *)temp->content);
			temp = temp->next;
		}
		
	}

}
