/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:17:07 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/08 18:00:34 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

int	color_by_radius(int x, int y)
{
	int	off_x;
	int	off_y;
	int	r;

	off_x = x - IMG_W_2;
	off_y = y - IMG_H_2;
	r = sqrt(pow(off_x, 2) + pow(off_y, 2));
	return (create_trgb(0, r, r * 0.87, 0));
}

int	color_mng_kt(t_mlx_data *data, int x, int y)
{
	
	if (data->color == 0)
		return (0x00FFD400);
	else if (data->color == 1)
		return (color_by_radius(x, y));
	else
		return (0x0000FF00);
}
