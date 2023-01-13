/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 15:48:42 by mvenanci@st      ###   ########.fr       */
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
		t_cmd *temp2 = (t_cmd *)temp->content;
		while (temp)
		{
			ft_printf("%s\n", temp2->path);
			temp = temp->next;
			if (temp)
				temp2 = (t_cmd *)temp->content;
		}
		
	}

}
