/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:42:40 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 13:52:56 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	ft_julia_mouse(int x, int y, t_fract *julia)
{
	if (julia->set == 1)
	{
		julia->c_real = julia->xmin + ((double)(x)*(julia->xmax
					- julia->xmin)) / WIDTH;
		julia->c_imag = julia->ymin + ((double)(y)*(julia->ymax
					- julia->ymin)) / HEIGHT;
		ft_julia(julia);
	}
	return (0);
}

void	ft_julia_init(t_fract *julia)
{
	julia->c_real = -0.8;
	julia->c_imag = 0.156;
	julia->zoom = 1.2;
	julia->xmin = -2;
	julia->xmax = 2;
	julia->ymin = -2;
	julia->ymax = 2;
	julia->offx = 0;
	julia->offy = 0;
	julia->color = 32769;
}

void	ft_julia_calc(t_fract *julia)
{
	julia->z_r = ((julia->x * (julia->xmax - julia->xmin))
			/ WIDTH) + julia->xmin + julia->shiftx;
	julia->z_i = ((julia->y * (julia->ymax - julia->ymin))
			/ HEIGHT) + julia->ymin + julia->shifty;
	julia->iteration = 0;
	while (julia->z_r * julia->z_r + julia->z_i * julia->z_i < 4
		&& julia->iteration < MAX_IT)
	{
		julia->tmp_r = julia->z_r * julia->z_r
			- julia->z_i * julia->z_i + julia->c_real;
		julia->tmp_i = 2 * julia->z_r * julia->z_i + julia->c_imag;
		julia->z_r = julia->tmp_r;
		julia->z_i = julia->tmp_i;
		julia->iteration++;
	}
}

void	ft_julia(t_fract *julia)
{
	julia->x = 0;
	mlx_clear_window(julia->mlx, julia->win);
	while (julia->x < WIDTH)
	{
		julia->y = 0;
		while (julia->y < HEIGHT)
		{
			ft_julia_calc(julia);
			if (julia->iteration == MAX_IT)
				julia->iteration = 0;
			julia->buffer[((int)((julia->y * julia->line_bytes) + julia->x))]
				= julia->iteration * 14 * julia->color;
			julia->y++;
		}
		julia->x++;
	}
	mlx_put_image_to_window(julia->mlx, julia->win,
		julia->image, 0, 0);
}
