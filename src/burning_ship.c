/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:35:44 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 14:14:59 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_ship_init(t_fract *ship)
{
	ship->zoom = 1.2;
	ship->xmin = -2;
	ship->xmax = 2;
	ship->ymin = -2;
	ship->ymax = 2;
	ship->offx = 0;
	ship->offy = 0;
	ship->shiftx = 0;
	ship->shifty = 0;
	ship->color = 32769;
}

void	ft_ship_calc(t_fract *ship)
{
	ship->c_real = ((ship->x * (ship->xmax - ship->xmin))
			/ WIDTH) + ship->xmin + ship->shiftx;
	ship->c_imag = ((ship->y * (ship->ymax - ship->ymin))
			/ HEIGHT) + ship->ymin + ship->shifty;
	ship->z_r = 0;
	ship->z_i = 0;
	ship->iteration = 0;
	while (ship->z_r * ship->z_r + ship->z_i * ship->z_i < 4
		&& ship->iteration < MAX_IT)
	{
		ship->tmp_r = ship->z_r * ship->z_r - ship->z_i
			* ship->z_i + ship->c_real;
		ship->tmp_i = fabs(2 * ship->z_r * ship->z_i) + ship->c_imag;
		ship->z_r = ship->tmp_r;
		ship->z_i = ship->tmp_i;
		ship->iteration++;
	}
}

void	ft_ship(t_fract *ship)
{
	ship->x = 0;
	mlx_clear_window(ship->mlx, ship->win);
	while (ship->x < WIDTH)
	{
		ship->y = 0;
		while (ship->y < HEIGHT)
		{
			ft_ship_calc(ship);
			if (ship->iteration == MAX_IT)
				ship->iteration = 0;
			ship->buffer[((int)((ship->y * ship->line_bytes) + ship->x))]
				= ship->iteration * 14 * ship->color;
			ship->y++;
		}
		ship->x++;
	}
	mlx_put_image_to_window(ship->mlx, ship->win,
		ship->image, 0, 0);
}
