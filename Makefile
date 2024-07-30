SRC		=	./help/gnl_1.c \
			./help/gnl_2.c \
			./help/helpfunc.c \
			./src/draw_line.c \
			./src/draw_map.c \
			./src/init.c \
			./src/key_hook.c \
			./src/main.c \
			./src/mouse_hooks.c \
			./src/transform.c \
			./src/update_frame.c \
			./src/view.c \
			./util/colors.c \
			./util/fdf_err.c \
			./util/fdf_map.c \
			./util/fdf_parc.c \
			./util/fdf_util.c \
			./util/lst_heap.c \
			./util/lst_img.c \
			./util/talloc.c \
			./util/terror.c

OBJ			=	$(SRC:.c=.o)
NAME		=	fdf
MLXFLAGS	=	-L/usr/local/lib -l mlx -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OBJ)
	@cc -Wall -Wextra -Werror $(OBJ) -o $(NAME) $(MLXFLAGS)

%.o: %.c ./src/fdf.h ./src/struct.h 
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
