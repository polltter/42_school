/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/03 17:14:31 by mvenanci@st      ###   ########.fr       */
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

	color = 0;
	seed = init_number(0, 0);
	real = -3840 / 2 - 1;
	while (++real <= 3840 / 2)
	{
		im = -2160 / 2 - 1;
		while (++im <= 2160 / 2)
		{
			pixel = init_number(real / 960, im / 960);
			temp = mandelbrot(seed, pixel);
			for (int po = 0; po < 30; po ++)
				temp = mandelbrot(temp, pixel);
/* 			printf("raio: %f, real:%f, im: %f\n", pixel.r, pixel.real, pixel.im);
			sleep(1); */
			if (temp.r > 2)
			{
				//color = create_trgb(0, )
				my_mlx_pixel_put(img, pixel.real * 960 / 2 + 1920 / 2, pixel.im * 960 / 2 + 1080 / 2, 0xFFFFFFFF);
			}
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

/* 	t_im	c =  init_number(0, 2);
	t_im	x =  init_number(0, 0);
	x = mandelbrot(x, c);
	printf("real %f, im %f, raio %f, theta %f\n", x.real, x.im, x.r, x.theta);
	x = mandelbrot(x, c);
	printf("real %f, im %f, raio %f, theta %f\n", x.real, x.im, x.r, x.theta);
	x = mandelbrot(x, c);
	printf("real %f, im %f, raio %f, theta %f\n", x.real, x.im, x.r, x.theta);
	x = mandelbrot(x, c);
	printf("real %f, im %f, raio %f, theta %f\n", x.real, x.im, x.r, x.theta);
	x = mandelbrot(x, c);
	printf("real %f, im %f, raio %f, theta %f\n", x.real, x.im, x.r, x.theta);

	return; */
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 3840, 2160);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	draw_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
