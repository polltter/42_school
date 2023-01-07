/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/07 17:25:23 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../INCS/fractol.h>

void	fractal_manager(t_mlx_data data)
{
	if (data.fractal_set == 'M')
		draw_mandelbrot(data, init_number(IMG_W_2, IMG_H_2));
	else if (data.fractal_set == 'J')
		draw_julia(data, data.seed);
	else if (data.fractal_set == 'K')
		draw_koch_snowflake(&data);
}

void	data_init(char **av, t_mlx_data *data)
{
	if (av)
	{
		data->mlx = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx, IMG_W, IMG_H, "Farct-ol!");
		data->img.img = mlx_new_image(data->mlx, IMG_W, IMG_H);
		data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
		data->fractal_set = av[1][0];
		data->color = 0;
	}
	data->scale = IMG_W / 4;
	data->kscale = 1;
	data->offset = init_number(0, 0);
	data->seed = init_number(0, 0);
	data->iterations = 0;
}

int	ft_close(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	handle_keys(int k, t_mlx_data *data)
{
	t_im	offset;

	if (k >= 65361 && k <= 65364)
		move(k, data);
	else if (k == 65307)
		ft_close(data);
	else if (k == 'a' || k == 'd' || k == 'w' || k == 's')
		change_seed(k, data);
	else if (k == 'r')
		data_init(NULL, data);
	else if (k == 'p')
		data->iterations += 1;
	else if (k == 'l')
		data->iterations -= 1;
	else if (k == 'm')
		color_change(data);
	fractal_manager(*data);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	(void) ac;
	data_init(av, &data);
	fractal_manager(data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_win, 2, 1l << 0, handle_keys, &data);
	mlx_hook(data.mlx_win, 4, 1l << 2, zoom, &data);
	mlx_loop(data.mlx);
}
