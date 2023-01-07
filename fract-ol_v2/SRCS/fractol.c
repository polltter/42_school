/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/31 01:37:12 by mvenanci         ###   ########.fr       */
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

void data_init(char **av, t_mlx_data *data)
{
	if (av)
	{
		data->mlx = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx, IMG_W, IMG_H, "Farct-ol!");
		data->img.img = mlx_new_image(data->mlx, IMG_W, IMG_H);
		data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
		&data->img.line_length, &data->img.endian);
		data->fractal_set = av[1][0];
	}
	data->scale = IMG_W / 4;
	data->kscale = 1;
	data->offset = init_number(0, 0);
	data->koffset = init_number(0, 0);
	data->seed = init_number(0, 0);
	data->iterations = 0;
}

int	ft_close(void *o)
{
	(void) o;
	exit(0);
	return (0);
}

void	handle_keys(int k , t_mlx_data *data)
{
	t_im	offset;

	if (k >= 65361 && k <= 65364)
	{
		if (data->fractal_set == 'K')
			kmove(k, data);
		else
			move(k, data);
	}
	else if (k == 65307)
		ft_close(0);
	else if (k == 'a' || k == 'd' || k == 'w' || k == 's')
		change_seed(k, data);
	else if (k == 'r')
		data_init(NULL, data);
	else if (k == 'p')
		data->iterations += 1;
	else if (k == 'l')
		data->iterations -= 1;
	fractal_manager(*data);
}

void	zoom(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4)
	{
		data->scale *= 1.5;
		data->kscale *= 1.5;
		data->offset = multiply_imaginary_by_scalar(data->offset, 1.5);
		data->offset = sum_imaginary(data->offset, \
		subtract_imaginary(init_number(IMG_W_2, IMG_H_2), init_number(x, y), \
		1));
		// data->koffset = sum_imaginary(data->koffset, \
		// subtract_imaginary(init_number(IMG_W_2, IMG_H_2), init_number(x, y), \
		data->kscale));
	}
	else if (button == 5)
	{
		data->scale /= 1.5;
		data->kscale /= 1.5;
		data->offset = multiply_imaginary_by_scalar(data->offset, 1 / 1.5);
	}
	fractal_manager(*data);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	(void) ac;
	data_init(av, &data);
	fractal_manager(data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, NULL);
	mlx_hook(data.mlx_win, 2, 1l << 0, handle_keys, &data);
	mlx_hook(data.mlx_win, 4, 1l << 2, zoom, &data);
	mlx_loop(data.mlx);
}
