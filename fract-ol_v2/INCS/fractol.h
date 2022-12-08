/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:57:15 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/08 15:14:24 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <../mlx_linux/mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <limits.h>

# define PI 3.14159265358979323846
# define IMG_W 800	
# define IMG_H 600
# define IMG_W_2 IMG_W / 2 
# define IMG_H_2 IMG_H / 2


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_im {
	double	real;
	double	im;
	double	r;
	double	theta;
}	t_im;


typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	scale;
	t_im	offset;
}	t_mlx_data;

//math functions
t_im	init_number(double real, double im);
double	raio(t_im n);
double	ang(t_im n);
t_im	sum_imaginary(t_im first, t_im second);
t_im	multiply_imaginary(t_im	frist, t_im second);
t_im	subtract_imaginary(t_im first, t_im second, double scale);
void	calc_real_im(t_im *n);

//fractal sets
t_im	mandelbrot(t_im pixel, t_im c);

//drawing
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_mandelbrot(t_data *img, t_im seed, t_im offset, double scale);

#endif