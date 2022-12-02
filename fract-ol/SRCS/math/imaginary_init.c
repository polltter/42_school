/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaginary_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:07:30 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/02 19:11:38 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	init_number(int real, int im)
{
	t_im	number;

	number.real = real;
	number.im = im;
	number.r = raio(number);
	number.theta = ang(number);
	return (number);
}

double	raio(t_im n)
{
	return (sqrt(pow(n.real, 2) + pow(n.im, 2)));
}

double	ang(t_im n)
{
	if ((n.real >= 0 && n.im >= 0) || n.real <= 0 && n.im <= 0)
		return (atan(n.im / n.real));
	else
		return (atan(n.im / n.real) + PI);
}

void	calc_real_im(t_im *n)
{
	n->real = (n->r) * cos(n->theta);
	n->im = (n->r) * sin(n->theta);
}
