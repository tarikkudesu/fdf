/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 10:11:56 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	// print_it(&fdf);
	make_it_3d(&fdf);
}