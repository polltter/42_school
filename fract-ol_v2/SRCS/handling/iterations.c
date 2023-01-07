/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:54:26 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/07 17:18:26 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

void	zoom(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4)
		zoom_in(x, y, data);
	else if (button == 5)
		zoom_out(x, y, data);
	fractal_manager(*data);
}

void	color_change(t_mlx_data *data)
{
	if (data->color == 2)
		data->color = 0;
	else
		data->color++;
}
