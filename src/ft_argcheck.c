/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:45 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 01:43:01 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	ft_str_isdiff(char *str, char *mystr)
{
	int	i;

	i = 0;
	while (str[i] || mystr[i])
	{
		if (str[i] != mystr[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_argcheck(char *s)
{
	if (!ft_str_isdiff(s, "mandelbrot"))
		return (0);
	else if (!ft_str_isdiff(s, "julia"))
		return (1);
	else if (!ft_str_isdiff(s, "burning_ship"))
		return (2);
	else
	{
		ft_putstr("HINT : \n./fractol mandelbrot\n");
		ft_putstr("./fractol julia\n./fractol burning_ship");
		exit(0);
	}
}
