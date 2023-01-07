/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaginary_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:53:42 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/31 00:18:56 by mvenanci         ###   ########.fr       */
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

	new.real = (first.real - second.real) / scale;
	new.im = (first.im - second.im) / scale;
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

t_im	multiply_imaginary_by_scalar(t_im	frist, double scalar)
{
	frist.real *= scalar;
	frist.im *= scalar;
	return (frist);
}
