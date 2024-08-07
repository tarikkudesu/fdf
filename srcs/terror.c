#include "../headers/fdf.h"

void	putendl_fd(char *s, int fd) {
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

int terror( char *__err_message ) {
    putendl_fd( __err_message, 2 );
    exit(EXIT_FAILURE);
}

int	exit_program(t_fdf *fdf) {
	if (fdf->mlx.__win)
		mlx_destroy_window(fdf->mlx.__mlx, fdf->mlx.__win);
	clearheap(&fdf->heap);
	exit(EXIT_SUCCESS);
}
