/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:05:33 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 13:20:24 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_close(void)
{
	exit(0);
}

int	ft_keyhook(int button, t_fract *fract)
{
	if (button == 53)
		exit(1);
	else if (button == 124)
		fract->shiftx += (fract->xmax - fract->xmin) / 10;
	else if (button == 123)
		fract->shiftx -= (fract->xmax - fract->xmin) / 10;
	else if (button == 126)
		fract->shifty -= (fract->ymax - fract->ymin) / 10;
	else if (button == 125)
		fract->shifty += (fract->ymax - fract->ymin) / 10;
	else if (button == 8)
		fract->color += 256;
	ft_draw(fract);
	return (0);
}

void	ft_init(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fractol");
	fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fract	*fract;

	if (ac != 2)
		return (0);
	ft_argcheck(av[1]);
	fract = (t_fract *)malloc(sizeof(t_fract));
	if (!fract)
		return (0);
	fract->set = ft_argcheck(av[1]);
	ft_init(fract);
	fract->buffer = (int *)mlx_get_data_addr(fract->image, &(fract->pixel_bits),
			&(fract->line_bytes), &(fract->endian));
	fract->line_bytes /= 4;
	ft_fract_init(fract);
	ft_draw(fract);
	mlx_hook(fract->win, 6, 1L << 7, ft_julia_mouse, fract);
	mlx_hook(fract->win, 17, 0, (void *)ft_close, NULL);
	mlx_key_hook(fract->win, ft_keyhook, fract);
	mlx_mouse_hook(fract->win, my_mouse_hook, fract);
	mlx_loop(fract->mlx);
	free(fract->mlx);
	system("leaks fractol");
	return (0);
}
