# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:02:48 by tamehri           #+#    #+#              #
#    Updated: 2024/02/22 11:47:41 by tamehri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	mand/src/fdf_main.c mand/src/fdf_image.c mand/src/draw_line.c mand/src/transform.c \
			mand/util/fdf_parc.c mand/util/fdf_map.c mand/util/fdf_util.c mand/util/fdf_err.c \
			mand/util/fdf_color.c mand/help/help.c mand/help/gnl_1.c mand/help/gnl_2.c

SRC_B	=	bonus/src/fdf_main_bonus.c bonus/src/fdf_image_bonus.c bonus/src/draw_line_bonus.c \
			bonus/src/fdf_view_bonus.c bonus/src/transform_bonus.c bonus/src/key_hook_bonus.c \
			bonus/src/fdf_mouse_bonus.c \
			bonus/util/fdf_parc_bonus.c bonus/util/fdf_map_bonus.c bonus/util/fdf_util_bonus.c \
			bonus/util/fdf_color_bonus.c bonus/util/fdf_err_bonus.c bonus/help/helpfunc_bonus.c \
			bonus/help/gnl_1_bonus.c bonus/help/gnl_2_bonus.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	fdf
BONUS		=	fdf_bonus
HEADER		=	mand/src/fdf.h mand/src/fdf_struct.h
HEADER_B	=	bonus/src/fdf_bonus.h bonus/src/fdf_struct_bonus.h
OBJ			=	$(SRC:.c=.o)
OBJ_B		=	$(SRC_B:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L /usr/local/lib -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)
	@echo $(GREEN) "compilation done\n" $(NONE)

$(BONUS): $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(BONUS) $(MLXFLAGS)
	@echo $(GREEN) "compilation done\n" $(NONE)

mand/%.o: mand/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)

bonus/%.o: bonus/%.c $(HEADER_B)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)

clean:
	@rm -f $(OBJ) $(OBJ_B)
	@echo $(GREEN) "clean done\n" $(NONE)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo $(GREEN) "fclean done\n" $(NONE)

re: fclean all
	@echo $(GREEN) "re done\n" $(NONE)

.PHONY: clean
