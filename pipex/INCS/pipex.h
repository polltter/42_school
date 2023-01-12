/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:14:07 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 21:01:59 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "../SRCS/ft_printf/ft_printf.h"

typedef struct s_cmds t_cmds;
typedef struct s_array t_array;

struct s_cmds{

	char	*cmd;
	t_cmds	*next;
};

struct s_array{

	t_cmds	*begin;
	t_cmds	*end;
	int		size;	
	void	(*lst_add_back)(t_cmds *elem_to_add, t_cmds *lst);
	void	(*lst_add_front)(t_cmds *elem_to_add, t_cmds *lst);
	int		(*lst_size)(t_cmds *elem_to_add, t_cmds *lst);
};

//parsing
char	*find_path_var(char **env);
char	**split(char *s, char c);

#endif