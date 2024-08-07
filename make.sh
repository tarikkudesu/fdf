#!/bin/sh

file=$(find . -name "*.c" -not -path "./MLX*" -not -path "./minilibx-linux*")
if [ $# -gt 0 ]; then
	cc -Wall -Wextra -Werror $file -o fdf -g -L./minilibx-linux -lmlx -lX11 -lXext -lm
else
	cc -Wall -Wextra -Werror $file -o fdf -g -L./minilibx-linux -lmlx -lX11 -lXext -lm
fi
