/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:11:39 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 14:06:06 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define MAX_X 2
# define MIN_X -2
# define MAX_Y 2
# define MIN_Y -2
# define HEIGHT 600
# define WIDTH 600
# define MAX_IT 250

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fract {
	void	*mlx;
	void	*win;
	void	*image;
	int		set;
	int		color;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	c_real;
	double	c_imag;
	double	z_r;
	double	z_i;
	double	tmp_r;
	double	tmp_i;
	double	x;
	double	y;
	double	real;
	double	imag;
	double	zoom;
	double	offx;
	double	offy;
	double	shiftx;
	double	shifty;
	int		iteration;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*buffer;
}	t_fract;

void	ft_fract_init(t_fract *fract);
int		ft_argcheck(char *s);
void	ft_mand_init(t_fract *fract);
void	ft_mandelbrot(t_fract *fract);
void	ft_zoom(t_fract *fract, double offx, double offy);
void	ft_dezoom(t_fract *fract, double offx, double offy);
int		my_mouse_hook(int button, int x, int y, t_fract *fract);
void	ft_mand_init(t_fract *fract);
void	ft_draw(t_fract *fract);
void	ft_julia_calc(t_fract *julia);
void	ft_julia_init(t_fract *julia);
void	ft_julia(t_fract *julia);
int		ft_julia_mouse(int x, int y, t_fract *julia);
void	ft_putstr(char	*str);
void	ft_ship(t_fract *ship);
void	ft_ship_init(t_fract *ship);

#endif