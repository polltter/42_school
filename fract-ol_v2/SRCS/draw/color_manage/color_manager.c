/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:01:46 by mvenanci          #+#    #+#             */
/*   Updated: 2022/12/17 16:13:11 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCS/fractol.h"

int	color_manager(t_im temp, t_im pixel, int iterations, int color_scheme)
{
	if (color_scheme == 0)
		return (get_color(temp, pixel));
	else if (color_scheme == 1)
		return (get_color_iter(iterations, color_scheme));
}

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
	int color;

	color = (55 - iter) * 255 / 50;
	return (create_trgb(0, color, color, color));
}