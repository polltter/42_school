/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:01:46 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/08 11:59:15 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCS/fractol.h"

int	get_color(t_im temp, t_im pixel)
{
	int	mult;
	int	t;
	int	u;

	t = (pixel.real * (IMG_W_2));
	u = (pixel.im * (IMG_W_2));
	mult = 1000;
	return (create_trgb(0, abs(t * t) / temp.r / mult, \
	abs(t * u) / temp.r / mult, u * u / temp.r / mult));
}

int	get_color_iter(int iter, int color_scheme)
{
	int	color;

	if (iter > 25)
	{
		color = iter * 255 / 32;
		return (create_trgb(0, color, color * 0.8, 0));
	}
	else
	{
		color = iter * 255 / 15;
		return (create_trgb(0, color, color * 0.75, color * 0.05));
	}
}

int	black_and_white_color(t_im temp, int iter)
{
	double	smooth;

	if (iter % 2)
		return (0);
	else
		return (0x00FFFFFF);
}

int	color_mng(t_im temp, t_im pixel, int iterations, int color_scheme)
{
	if (color_scheme == 0)
		return (get_color(temp, pixel));
	else if (color_scheme == 1)
		return (get_color_iter(iterations, color_scheme));
	else if (color_scheme == 2)
		return (black_and_white_color(temp, iterations));
}
