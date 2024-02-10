/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 11:06:18 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_it_3d(t_fdf *fdf)
{
	t_ui	ui;
	t_img	img;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_struct(fdf), ft_putstr_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_struct(fdf), ft_putstr_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->img = &img;
	fdf->ui = &ui;
	panel(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->intro, 0, 0);
	fill_image(fdf);
	mlx_hook(fdf->win, 2, 0, &handle_key, fdf);
	mlx_mouse_hook(fdf->win, &handle_mouse, fdf);
	mlx_loop(fdf->mlx);
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	if (!check_filename(file_name))
		(ft_putstr_fd(ERR_ARG, 2), exit(1));
	read_file(file_name, fdf);
	fdf->color_map = init_color_map(fdf);
	fdf->map = get_map(fdf, file_name);
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->z_zoom = 1;
	fdf->x_offset = 400 + (WIDTH - 400) / 2;
	fdf->y_offset = HEIGHT / 2;
	fdf->x_translate = 0;
	fdf->y_translate = 0;
	fdf->color = 0x76EFF0;
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
	fdf->iso = 1;
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		(ft_putstr_fd(ERR_ARG, 2), exit(1));
	init_fdf(&fdf, av[1]);
	make_it_3d(&fdf);
}