/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:01:46 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/07 19:40:20 by mvenanci@st      ###   ########.fr       */
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

	color = iter * 255 / 32 + 10;
	return (create_trgb(0, color / 2, color, color / 3));
}

int	cont_smooth_color(t_im temp, int iterations)
{
	double	smooth;

	smooth = log(log(temp.r * pow(IMG_H / 4, 2)) / log(2));
	return (create_trgb(0, smooth, 0, 0));
}

int	color_mng(t_im temp, t_im pixel, int iterations, int color_scheme)
{
	if (color_scheme == 0)
		return (get_color(temp, pixel));
	else if (color_scheme == 1)
		return (get_color_iter(iterations, color_scheme));
	else if (color_scheme == 2)
		return (cont_smooth_color(temp, iterations));
}
