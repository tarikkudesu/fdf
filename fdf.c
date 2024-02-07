/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/07 11:14:11 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_zoom(t_fdf *fdf)
{
	if (fdf->width < 100)
		return (10);
	if (fdf->width < 200)
		return (7);
	if (fdf->width < 300)
		return (6);
	if (fdf->width < 400)
		return (5);
	if (fdf->width < 500)
		return (4);
	if (fdf->width < 600)
		return (3);
	return (2);
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	if (!check_filename(file_name))
		(ft_putstr_fd(ERR_ARG, 2), exit(1));
	read_file(file_name, fdf);
	fdf->color_map = init_color_map(fdf);
	fdf->map = get_map(fdf, file_name);
	fdf->zoom = 10;
	fdf->z_zoom = 5;
	fdf->x_offset = WIDTH / 2 - (fdf->width / 2) * fdf->zoom;
	fdf->y_offset = HEIGHT / 2 - (fdf->height / 2) * fdf->zoom;
	fdf->color = 0x76EFF0;
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		(ft_putstr_fd(ERR_ARG, 2), exit(1));
	init_fdf(&fdf, av[1]);
	// print_it(&fdf);
	make_it_3d(&fdf);
}