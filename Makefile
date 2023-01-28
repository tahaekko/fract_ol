CC = cc -Oz
FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC =  mandelbrot.c
NAME = mandelbrot

all : $(NAME)

$(NAME): $(SRC) fract_ol.h
	$(CC) $(FLAGS) $(SRC) -o $(NAME)