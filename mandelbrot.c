/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:05:33 by msamhaou          #+#    #+#             */
/*   Updated: 2023/01/28 02:31:16 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mandelbrot(t_fract *mand);

void	ft_zoom(t_fract *mand, int offx, int offy)
{
	mand->xmin = offx + ((mand->xmin - offx) / mand->zoom);
	mand->xmax = offx + ((mand->xmax - offx) / mand->zoom);
	mand->ymin = offy + ((mand->ymin - offy) / mand->zoom);
	mand->ymax = offy + ((mand->ymax - offy) / mand->zoom);
	//printf("IN XMIN:%f\n", mand->xmin);
	//printf("IN XMAX:%f\n", mand->xmax);
	//printf("IN YMIN:%f\n", mand->ymin);
	//printf("IN YMAX:%f\n", mand->ymax);
	//printf("---------------------\n");
	mandelbrot(mand);
}

void	ft_dezoom(t_fract *mand, int offx, int offy)
{
	mand->xmin = offx + ((mand->xmin - offx) * mand->zoom);
	mand->xmax = offx + ((mand->xmax - offx) * mand->zoom);
	mand->ymin = offy - ((mand->ymin - offy) * mand->zoom);
	mand->ymax = offy - ((mand->ymax - offy) * mand->zoom);
	//printf("IN XMIN:%f\n", mand->xmin);
	//printf("OUT offx:%f\n", mand->offx);
	mandelbrot(mand);
}

void	mand_calc(t_fract *mand)
{
	mand->c_real = (mand->x * (mand->xmax - mand->xmin) / WIDTH) + mand->xmin;
	mand->c_imag =  (mand->y * (mand->ymax - mand->ymin) / HEIGHT) + mand->ymin;
	mand->z_real = 0;
	mand->z_imag = 0;
	mand->iteration = 0;
	while (mand->z_real * mand->z_real + mand->z_imag * mand->z_imag < 4 && mand->iteration < MAX_IT)
	{
		mand->tmp_real = mand->z_real * mand->z_real -  mand->z_imag * mand->z_imag + mand->c_real;
		mand->tmp_imag = 2 * mand->z_real * mand->z_imag + mand->c_imag;
		mand->z_real = mand->tmp_real;
		mand->z_imag = mand->tmp_imag;
		mand->iteration++;
	}
}

void	mandelbrot(t_fract *mand)
{
	mand->x = 0;
	mlx_clear_window(mand->mlx, mand->win);
	while (mand->x < WIDTH)
	{
		mand->y = 0;
		while (mand->y < HEIGHT)
		{
			mand_calc(mand);
			if (mand->iteration == MAX_IT)
				mand->iteration = 0;
			mand->buffer[((int)((mand->y * mand->line_bytes) + mand->x))] = mand->iteration * 14/*mand->iteration * (243 * 255 + 200)*/;
			mand->y++;
		}
		mand->x++;
	}
	mlx_put_image_to_window(mand->mlx, mand->win,
		mand->image, 0, 0);
}

int	my_mouse_hook(int button, int x, int y, t_fract *mand)
{
	mand->offx = (x * (mand->xmax - mand->xmin) / WIDTH) + mand->xmin;
	mand->offy = (y  * (mand->ymax - mand->ymin) / HEIGHT) + mand->ymin;
	if (button == 4)
	{
		ft_zoom(mand, mand->offx, mand->offy);
	}
	else if (button == 5)
		ft_dezoom(mand, x, y);
	return (0);
}

void	ft_close()
{
	exit(0);
}

int	main()
{
	t_fract	*mand;

	mand = (t_fract *)malloc(sizeof(t_fract));
	if (!mand)
		return (0);
	mand->mlx = mlx_init();
	mand->win = mlx_new_window(mand->mlx, WIDTH, HEIGHT, "ZEB");
	mand->image = mlx_new_image(mand->mlx, WIDTH,HEIGHT);
	mand->buffer= (int *)mlx_get_data_addr(mand->image, &(mand->pixel_bits), &(mand->line_bytes), &(mand->endian));
	mand->line_bytes /= 4;
	mand->zoom = 1.2;
	mand->xmin = -2;
	mand->xmax = 2;
	mand->ymin = -2;
	mand->ymax = 2;
	mand->offx = 0;
	mand->offy = 0;



	mandelbrot(mand);
	mlx_hook(mand->win, 17, 0, (void *)ft_close, NULL);
	mlx_put_image_to_window(mand->mlx, mand->win, mand->image, 0, 0);
	mlx_mouse_hook(mand->win, my_mouse_hook, mand);
	mlx_loop(mand->mlx);
}
