/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaginary_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:53:42 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/08 15:18:28 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	sum_imaginary(t_im first, t_im second)
{
	t_im	new;

	new.real = (first.real + second.real);
	new.im = (first.im + second.im);
	new.theta = ang(new);
	new.r = raio(new);
	return (new);
}

t_im	subtract_imaginary(t_im first, t_im second, double scale)
{
	t_im	new;

	new.real = (first.real - second.real) / (IMG_W / scale);
	new.im = (first.im - second.im) / (IMG_W / scale);
	new.theta = ang(new);
	new.r = raio(new);
	return (new);
}

t_im	multiply_imaginary(t_im	frist, t_im second)
{
	t_im	new;

	new.r = frist.r * second.r;
	new.theta = frist.theta + second.theta;
	calc_real_im(&new);
	return (new);
}
