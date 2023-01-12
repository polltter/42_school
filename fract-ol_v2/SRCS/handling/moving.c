/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:21:30 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/10 20:34:22 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	move(int keycode, t_mlx_data *data)
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

void	kmove(int keycode, t_mlx_data *data)
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

void	change_seed(int keycode, t_mlx_data *data)
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

void	zoom_in(int x, int y, t_mlx_data *data)
{
	data->scale *= 1.1;
	data->kscale *= 1.5;
	data->offset = multiply_imaginary_by_scalar(data->offset, 1.1);
	data->offset = sum_imaginary(data->offset, \
	subtract_imaginary(init_number(IMG_W_2, IMG_H_2), init_number(x, y), \
	10));
}

void	zoom_out(int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	data->scale /= 1.5;
	data->kscale /= 1.5;
	data->offset = multiply_imaginary_by_scalar(data->offset, 1 / 1.5);
}
