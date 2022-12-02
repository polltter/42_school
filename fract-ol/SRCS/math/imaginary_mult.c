/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaginary_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:53:42 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/02 19:17:33 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	sum_imaginary(t_im first, t_im second)
{
	t_im	new;

	new.real = first.real + second.real;
	new.im = first.im + second.im;
	new.theta = ang(new);
	new.r = raio(new);
}

t_im	multiply_imaginary(t_im	frist, t_im second)
{
	t_im	new;

	new.r = frist.r;
	new.theta = frist.theta + second.theta;
	calc_real_im(&new);
	return (new);
}