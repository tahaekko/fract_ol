#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_X 2
#define MIN_X -2
#define MAX_Y 2
#define MIN_Y -2
#define HEIGHT 1000
#define WIDTH 1000
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

