/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:21:30 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/30 23:42:37 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	move(int keycode , t_mlx_data *data)
{
	if (keycode == 65361)
		data->offset = sum_imaginary(data->offset, init_number(100, 0));
	else if (keycode == 65363)
		data->offset = sum_imaginary(data->offset, init_number(-100, 0));
	else if (keycode == 65362)
		data->offset = sum_imaginary(data->offset, init_number(0, 100));
	else if (keycode == 65364)
		data->offset = sum_imaginary(data->offset, init_number(0, -100));
	else if (keycode == 65307)
		ft_close(0);
}

void	kmove(int keycode , t_mlx_data *data)
{
	if (keycode == 65361)
		data->koffset = sum_imaginary(data->koffset, init_number(100, 0));
	else if (keycode == 65363)
		data->koffset = sum_imaginary(data->koffset, init_number(-100, 0));
	else if (keycode == 65362)
		data->koffset = sum_imaginary(data->koffset, init_number(0, 100));
	else if (keycode == 65364)
		data->koffset = sum_imaginary(data->koffset, init_number(0, -100));
}

void	change_seed(int keycode , t_mlx_data *data)
{
	if (keycode == 'a')
		data->seed = sum_imaginary(data->seed, init_number(-0.025, 0));
	else if (keycode == 'd')
		data->seed = sum_imaginary(data->seed, init_number(0.025, 0));
	else if (keycode == 'w')
		data->seed = sum_imaginary(data->seed, init_number(0, 0.025));
	else if (keycode == 's')
		data->seed = sum_imaginary(data->seed, init_number(0, -0.025));	
}