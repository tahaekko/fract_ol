/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:26:30 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 01:43:56 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_draw(t_fract *fract)
{
	if (fract->set == 0)
		ft_mandelbrot(fract);
	else if (fract->set == 1)
		ft_julia(fract);
	else if (fract->set == 2)
		ft_ship(fract);
}
