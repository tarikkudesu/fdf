# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:02:48 by tamehri           #+#    #+#              #
#    Updated: 2024/02/10 16:37:28 by tamehri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/fdf_bonus.c src/fdf_image.c src/draw_line.c src/fdf_view.c src/transform.c src/key_hook.c \
			libft/libft.c libft/gnl_1.c libft/gnl_2.c \
			util/fdf_parc.c util/fdf_map.c util/fdf_util.c util/fdf_err.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	fdf
HEADER		=	src/fdf_bonus.h
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
