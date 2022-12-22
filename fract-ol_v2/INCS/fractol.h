/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:57:15 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/22 19:54:04 by mvenanci         ###   ########.fr       */
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
# define IMG_W 1000	
# define IMG_H 800
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
	t_im	seed;
	char	fractal_set;
	int		iterations;
}	t_mlx_data;

//math functions
t_im	init_number(double real, double im);
double	raio(t_im n);
double	ang(t_im n);
t_im	sum_imaginary(t_im first, t_im second);
t_im	multiply_imaginary(t_im	frist, t_im second);
t_im	subtract_imaginary(t_im first, t_im second, double scale);
void	calc_real_im(t_im *n);
t_im	find_coords(t_im a, double ang, double side);
int		find_color(t_mlx_data *data, t_im first);
int		compare_coords(t_im a, t_im b);

//fractal sets
t_im	mandelbrot(t_im pixel, t_im c);
t_im	julia(t_im pixel, t_im c);

//drawing
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_mandelbrot(t_mlx_data data, t_im seed);
void	draw_julia(t_mlx_data data, t_im seed);
int		get_color(t_im temp, t_im pixel);
int		color_manager(t_im temp, t_im pixel, int iterations, int color_scheme);
int		get_color_iter(int iter, int color_scheme);
void	draw_koch_snowflake(t_mlx_data *data);


#endif