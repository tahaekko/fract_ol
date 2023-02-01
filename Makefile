# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:15:58 by msamhaou          #+#    #+#              #
#    Updated: 2023/02/01 14:15:59 by msamhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
LBFLAGS = -O2 -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src
SRC_FILE = fractol.c	ft_argcheck.c	ft_draw.c	ft_zoom.c	mandelbrot.c	tools.c	julia.c	burning_ship.c

OBJ_DIR = obj
OBJ_FILE = $(SRC_FILE:.c=.o)

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILE))

NAME = fractol

all : $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LBFLAGS) $^ -o $@
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c fract_ol.h
	$(CC) $(FLAGS) -c -o $@ $<
$(OBJ_DIR) :
	mkdir -p obj
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -rf $(NAME)
re : fclean all

