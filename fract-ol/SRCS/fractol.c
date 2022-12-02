/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/02 18:52:47 by mvenanci@st      ###   ########.fr       */
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
	t_im			pixel;
	t_im			center;
	int				color;
	int				n;

	center.im = 1080 / 2;
	center.real = 1920 / 2;
	pixel.real = -1;
	while (++pixel.real <= 1920)
	{
		pixel.im = -1;
		while (++pixel.im <= 1080)
		{
			if (sqrt(pow(pixel.real - center.real, 2) \
			+ pow(pixel.im - center.im, 2)) <= 255)
			{
				n = sqrt(pow(pixel.real - center.real, 2) + pow(pixel.im - center.im, 2));
				color = create_trgb(n, n, n, n);
				my_mlx_pixel_put(img, pixel.real, pixel.im, color);
			}	
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	draw_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
