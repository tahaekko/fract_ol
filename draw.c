/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:28:39 by msamhaou          #+#    #+#             */
/*   Updated: 2023/01/24 16:40:36 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"



int	main()
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "LOl");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);

	int pixel_bits;
	int	line_bytes;
	int endian;
	int *buffer = (int *)mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;
	
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			buffer[(int)((j * line_bytes) + i)] = 243 * 255 + 200;
		}
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_mouse_hook(win, my_mouse_press, NULL);
	mlx_loop(mlx);
}