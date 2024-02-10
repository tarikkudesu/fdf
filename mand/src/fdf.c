/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 20:49:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	null_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->map = NULL;
	fdf->a = NULL;
	fdf->b = NULL;
}

void	null_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
}


void	make_it_3d(t_fdf *fdf)
{
	t_img	img;

	null_img(&img);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_array(fdf->map), ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_array(fdf->map), ft_putendl_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_array(fdf->map), ft_putendl_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->img = &img;
	fill_image(fdf);
	mlx_loop(fdf->mlx);
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	if (!check_filename(file_name))
		(ft_putendl_fd(ERR_FILE, 2), exit(1));
	null_fdf(fdf);
	read_file(file_name, fdf);
	fdf->map = get_map(fdf, file_name);
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->x_offset = WIDTH / 2;
	fdf->y_offset = HEIGHT / 2;
	fdf->color = 0x76EFF0;
}

void	f() {system("leaks fdf");}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	atexit(f);
	if (ac != 2)
		(ft_putendl_fd(ERR_ARG, 2), exit(1));
	init_fdf(&fdf, av[1]);
	make_it_3d(&fdf);
}
