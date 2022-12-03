/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:05:43 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/12/03 12:25:47 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

t_im	mandelbrot(t_im pixel, t_im c)
{
	return (sum_imaginary(multiply_imaginary(pixel, pixel), c));
}
