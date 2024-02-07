# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:02:48 by tamehri           #+#    #+#              #
#    Updated: 2024/02/07 20:00:54 by tamehri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	fdf.c fdf_utils.c fdf_parc.c fdf_map.c error.c \
			libft/libft.c libft/get_next_line.c libft/get_next_line_utils.c \
			fdf_draw/fdf_draw.c fdf_draw/math.c fdf_draw/key_hook.c fdf_draw/transform.c \
			fdf_draw/draw_line.c print.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	fdf
HEADER		=	fdf.h
OBJ			=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-I /usr/local/include -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit

all: $(NAME) clean

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)
	

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)
	@echo $(GREEN) "compilation done\n" $(NONE)

clean:
	@rm -f $(OBJ)
	@echo $(GREEN) "clean done\n" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) "fclean done\n" $(NONE)

re: fclean all
	@echo $(GREEN) "re done\n" $(NONE)
