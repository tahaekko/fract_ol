/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:28:39 by msamhaou          #+#    #+#             */
/*   Updated: 2023/01/18 04:25:02 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	my_mouse_press(int button, int x, int y, void *param)
{
	if (button == 4)
		printf("DOWN\n");
	else if (button == 5)
		printf("UP\n");
	return (0);
}

int	main()
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT,mlx);
	mlx_mouse_hook(win, my_mouse_press, NULL);
	mlx_loop(mlx);
}