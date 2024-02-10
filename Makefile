# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:02:48 by tamehri           #+#    #+#              #
#    Updated: 2024/02/10 20:48:19 by tamehri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	mand/src/fdf.c mand/src/fdf_image.c mand/src/draw_line.c \
			mand/libft/libft.c mand/libft/gnl_1.c mand/libft/gnl_2.c \
			mand/util/fdf_parc.c mand/util/fdf_map.c mand/util/fdf_util.c mand/util/fdf_err.c

SRC_B	=	bonus/src/fdf_bonus.c bonus/src/fdf_image.c bonus/src/draw_line.c bonus/src/fdf_view.c bonus/src/transform.c bonus/src/key_hook.c \
			bonus/libft/libft.c bonus/libft/gnl_1.c bonus/libft/gnl_2.c \
			bonus/util/fdf_parc.c bonus/util/fdf_map.c bonus/util/fdf_util.c bonus/util/fdf_err.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	fdf
HEADER		=	mand/src/fdf_bonus.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-I /usr/local/include -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit

all: $(NAME) clean

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)
	

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)~
	@echo $(GREEN) "compilation done\n" $(NONE)

clean:
	@rm -f $(OBJ)
	@echo $(GREEN) "clean done\n" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) "fclean done\n" $(NONE)

re: fclean all
	@echo $(GREEN) "re done\n" $(NONE)
