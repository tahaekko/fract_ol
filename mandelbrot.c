/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:05:33 by msamhaou          #+#    #+#             */
/*   Updated: 2023/01/18 04:34:21 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	my_mouse_press(int button)
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
	void	*image;
	complex	c;
	complex	z;
	double	i;
	double	j;
	double	real;
	double	imag;
	int	iteration;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "ZEB");
	image = mlx_new_image(mlx, WIDTH,HEIGHT);
	int pixel_bits;
	int line_bytes;
	int endian;
	int *buffer;
	buffer= (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;
	
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			c.real = (i * 4) / WIDTH - 2;
			c.imag = 2 - ((j * 4) / HEIGHT);
			z.real = 0;
			z.imag = 0;
			iteration = 0;
			while (z.real * z.real + z.imag * z.imag < 4 && iteration < MAX_IT)
			{
				real = z.real * z.real -  z.imag * z.imag + c.real;
				imag = 2 * z.real * z.imag + c.imag;
				z.real = real;
				z.imag = imag;
				iteration++;
			}
			if (iteration == MAX_IT)
				iteration = 0;
			buffer[((int)((j * line_bytes) + i))] = iteration * 14;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_mouse_hook(win, my_mouse_press, NULL);
	mlx_loop(mlx);
}
