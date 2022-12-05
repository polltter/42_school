/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/05 18:24:02 by mvenanci@st      ###   ########.fr       */
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

void	draw_line(t_data *img)
{
	t_im	pixel;
	t_im	seed;
	t_im	temp;
	int		i;
	int		color;
	double	real;
	double	im;
	int x = 0, y;
	int	flag;

	color = 0;
	seed = init_number(0, 0);
	real = -IMG_W / 2 - 1;
	while (++real < IMG_W / 2)
	{
		im = -IMG_H / 2 - 1;
		y = 0;
		while (++im < IMG_H / 2)
		{
			pixel = init_number(real / (IMG_W / 4), im / (IMG_W / 4));
			temp = mandelbrot(seed, pixel);
			flag = 0;
			for (int po = 0; po < 100; po ++)
			{
				temp = mandelbrot(temp, pixel);
				if (temp.r > 2)
				{
					int mult = 1000;
					color = create_trgb(0, x*x / temp.r / mult, x*y / temp.r / mult, y*y / temp.r/ mult);
					my_mlx_pixel_put(img, x, y, color);
					flag = 1;
					break ;
				}
			}
			if (!flag)
			{
				int mult = 3000;
				color = create_trgb(0, x*x / temp.r / mult, x*y / temp.r / mult, y*y / temp.r/ mult);
				my_mlx_pixel_put(img, x, y, color);
			}
			y++;
		}
		x++;
	}
}

int	ft_close(void *o)
{
	(void) o;
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, IMG_W, IMG_H, "Hello world!");
	img.img = mlx_new_image(mlx, IMG_W, IMG_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	draw_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 0, ft_close, NULL);
	mlx_loop(mlx);
}
