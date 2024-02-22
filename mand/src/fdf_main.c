/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/22 12:02:31 by tamehri          ###   ########.fr       */
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

int	get_z_zoom(t_fdf *fdf)
{
	int	max;

	if (abs(fdf->max) > abs(fdf->min))
		max = abs(fdf->max);
	else
		max = abs(fdf->min);
	if (max <= 5)
		return (40);
	else if (max <= 10)
		return (20);
	else if (max <= 30)
		return (10);
	else if (max <= 50)
		return (5);
	else if (max <= 100)
		return (2);
	else
		return (1);
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
	fdf->z_zoom = get_z_zoom(fdf);
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
}

void	make_it_3d(t_fdf *fdf)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	fdf->img = &img;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_array(fdf->map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_IMG, 2), mlx_destroy_window(fdf->mlx, fdf->win), \
		exit(EXIT_FAILURE));
	fill_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	mlx_hook(fdf->win, 17, 0, &exit_program, fdf);
	mlx_hook(fdf->win, 2, 0, &handle_key, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		(ft_putendl_fd(ERR_ARG, 2), exit(1));
	init_fdf(&fdf, av[1]);
	make_it_3d(&fdf);
	return (0);
}
