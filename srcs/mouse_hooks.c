# include "../headers/fdf.h"

int	mouse_release(int button, int x, int y, t_fdf *fdf) {
    // puts("mouse release");
	(void)x;
	(void)y;
	(void)fdf;
	(void)button;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf) {
    // puts("mouse move");
	(void)x;
	(void)y;
	(void)fdf;
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf) {
    // puts("mouse press");
    printf("%d\n", button);
	(void)x;
	(void)y;
	(void)fdf;
	// (void)button;
	return (0);
}