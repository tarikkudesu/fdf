# include "../headers/fdf.h"

void    initTextures( t_fdf *fdf ) {
    (void)fdf;
}

static void	init_mlx(t_fdf *fdf) {
	fdf->mlx.__mlx = mlx_init();
	if (!fdf->mlx.__mlx)
		terror(ERR_MLX_INIT);
	fdf->mlx.__win = mlx_new_window(fdf->mlx.__mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->mlx.__win)
		terror(ERR_MLX_WIN);
	fdf->image.__img = mlx_new_image(fdf->mlx.__mlx, WIDTH, HEIGHT);
	if (!fdf->image.__img)
		terror(ERR_MLX_IMG);
	fdf->image.__addr = (int *)mlx_get_data_addr(fdf->image.__img, \
	&fdf->image.pixel_bits, &fdf->image.line_bytes, &fdf->image.endian);
	if (!fdf->image.__addr)
		terror(ERR_MLX_ADDRESS);
	initTextures(fdf);
}

void    initWindow( t_fdf *fdf ) {
	init_mlx(fdf);
	mlx_loop_hook(fdf->mlx.__mlx, update_frame, fdf);
	mlx_hook(fdf->mlx.__win, ON_KEYUP, 1L<<1, key_up, fdf);
	mlx_hook(fdf->mlx.__win, ON_KEYDOWN, 1L<<0, key_down, fdf);
	mlx_hook(fdf->mlx.__win, ON_MOUSEMOVE, 1L<<6, mouse_move, fdf);
	mlx_hook(fdf->mlx.__win, ON_MOUSEDOWN, 1L<<2, mouse_press, fdf);
	mlx_hook(fdf->mlx.__win, ON_MOUSEUP, 1L<<3, mouse_release, fdf);
	mlx_hook(fdf->mlx.__win, ON_DESTROY, 0, exit_program, fdf);
	mlx_loop(fdf->mlx.__mlx);
}
