CC = cc
FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC =  mandelbrot.c
NAME = mandelbrot

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)