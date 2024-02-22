/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/22 11:46:52 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	if (!check_filename(file_name))
		(ft_putendl_fd(ERR_FILE, 2), exit(1));
	null_fdf(fdf);
	read_file(file_name, fdf);
	fdf->max = 0;
	fdf->min = 0;
	fdf->colors = 0;
	fdf->color_map = init_color_map(fdf);
	fdf->map = get_map(fdf, file_name);
	if (!fdf->colors)
		init_color_map_grediant(fdf);
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->z_incr = 1;
	fdf->x_translate = 0;
	fdf->y_translate = 0;
	fdf->pressed = 0;
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
	fdf->iso = 1;
}

void	make_it_3d(t_fdf *fdf)
{
	t_ui	ui;
	t_img	img;

	null_ui(&ui);
	img.img = NULL;
	img.addr = NULL;
	init_window(fdf);
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_IMG, 2), mlx_destroy_window(fdf->mlx, fdf->win), \
		exit(EXIT_FAILURE));
	fdf->ui = &ui;
	fdf->img = &img;
	panel(fdf);
	fill_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->intro, 0, 0);
	mlx_hook(fdf->win, 2, 0, &handle_key, fdf);
	mlx_hook(fdf->win, 4, 0, &handle_mouse, fdf);
	mlx_hook(fdf->win, 5, 0, &handle_mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, &handle_mouse_move, fdf);
	mlx_hook(fdf->win, 17, 0, &exit_program, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		(ft_putendl_fd(ERR_ARG, 2), exit(1));
	init_fdf(&fdf, av[1]);
	make_it_3d(&fdf);
}
