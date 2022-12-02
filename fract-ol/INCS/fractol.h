/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:57:15 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/02 19:17:40 by mvenanci@st      ###   ########.fr       */
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

# define PI 3.14159265358979323846

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


//math functions
t_im	init_number(int real, int im);
double	raio(t_im n);
double	ang(t_im n);
t_im	sum_imaginary(t_im first, t_im second);
t_im	multiply_imaginary(t_im	frist, t_im second);
void	calc_real_im(t_im *n);


#endif