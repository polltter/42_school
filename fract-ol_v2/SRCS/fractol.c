/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/10 01:08:11 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../INCS/fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_close(void *o)
{
	(void) o;
	exit(0);
	return (0);
}

int	close_esc(int keycode, t_mlx_data *data)
{
	if (keycode == 65307)
		ft_close(0);
	else if (keycode == 113)
		return (1);
	else if (keycode == 97)
		return (1);
	return (0);
}

void move(int keycode , t_mlx_data *data)
{
	t_im	offset;

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
	draw_mandelbrot(&(data->img), init_number(IMG_W_2, IMG_H_2), data->offset, \
	data->scale);
	mlx_put_image_to_window(data->mlx, data->mlx_win, (data->img).img, 0, 0);
}

void	zoom(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4)
	{
		data->scale *= 1.5;
		data->offset.real *= 1.5;
		data ->offset.im *= 1.5;
	}
	else if (button == 5)
	{
		data->scale /= 1.5;
		data->offset.real /= 1.5;
		data ->offset.im /= 1.5;
	}
	draw_mandelbrot(&(data->img), init_number(IMG_W_2, IMG_H_2), data->offset, \
	data->scale);
	mlx_put_image_to_window(data->mlx, data->mlx_win, (data->img).img, 0, 0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, IMG_W, IMG_H, "Farct-ol!");
	data.img.img = mlx_new_image(data.mlx, IMG_W, IMG_H);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_length, &data.img.endian);
	data.scale = IMG_W / 4;
	data.offset = init_number(0, 0);
	draw_mandelbrot(&(data.img), init_number(IMG_W_2, IMG_H_2), data.offset, \
	data.scale);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 0, ft_close, NULL);
	mlx_hook(data.mlx_win, 2, 1L << 0, close_esc, &data);
	mlx_hook(data.mlx_win, 2, 1l << 0, move, &data);
	mlx_hook(data.mlx_win, 4, 1l << 2, zoom, &data);
	mlx_loop(data.mlx);
}
