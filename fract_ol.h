#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_X 2
#define MIN_X -2
#define MAX_Y 2
#define MIN_Y -2
#define HEIGHT 800
#define WIDTH 800
#define MAX_IT 250


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_complex
{
	double	real;
	double	imag;
} complex;

typedef struct s_fract {
	void	*mlx;
	void	*win;
	void	*image;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	c_real;
	double	c_imag;
	double	z_real;
	double	z_imag;
	double	tmp_real;
	double	tmp_imag;
	double	x;
	double	y;
	double	real;
	double	imag;
	double	zoom;
	double	offx;
	double	offy;
	int	iteration;
	int pixel_bits;
	int line_bytes;
	int endian;
	int *buffer;
} t_fract;

