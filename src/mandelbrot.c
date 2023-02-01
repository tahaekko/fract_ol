/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:37:04 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 13:59:45 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_mand_init(t_fract *mand)
{
	mand->zoom = 1.2;
	mand->xmin = -2;
	mand->xmax = 2;
	mand->ymin = -2;
	mand->ymax = 2;
	mand->offx = 0;
	mand->offy = 0;
	mand->shiftx = 0;
	mand->shifty = 0;
	mand->color = 32769;
}

void	ft_mand_calc(t_fract *mand)
{
	mand->c_real = ((mand->x * (mand->xmax - mand->xmin))
			/ WIDTH) + mand->xmin + mand->shiftx;
	mand->c_imag = ((mand->y * (mand->ymax - mand->ymin))
			/ HEIGHT) + mand->ymin + mand->shifty;
	mand->z_r = 0;
	mand->z_i = 0;
	mand->iteration = 0;
	while (mand->z_r * mand->z_r + mand->z_i * mand->z_i < 4
		&& mand->iteration < MAX_IT)
	{
		mand->tmp_r = mand->z_r * mand->z_r
			- mand->z_i * mand->z_i + mand->c_real;
		mand->tmp_i = 2 * mand->z_r * mand->z_i + mand->c_imag;
		mand->z_r = mand->tmp_r;
		mand->z_i = mand->tmp_i;
		mand->iteration++;
	}
}

void	ft_mandelbrot(t_fract *mand)
{
	mand->x = 0;
	mlx_clear_window(mand->mlx, mand->win);
	while (mand->x < WIDTH)
	{
		mand->y = 0;
		while (mand->y < HEIGHT)
		{
			ft_mand_calc(mand);
			if (mand->iteration == MAX_IT)
				mand->iteration = 0;
			mand->buffer[((int)((mand->y * mand->line_bytes) + mand->x))]
				= mand->iteration * 14 * mand->color;
			mand->y++;
		}
		mand->x++;
	}
	mlx_put_image_to_window(mand->mlx, mand->win,
		mand->image, 0, 0);
}
