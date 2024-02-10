/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:00:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 20:42:25 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	exit_program(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	free_array(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_image(fdf->mlx, fdf->ui->intro);
	mlx_destroy_image(fdf->mlx, fdf->ui->iso_panel);
	mlx_destroy_image(fdf->mlx, fdf->ui->ortho_panel);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(EXIT_SUCCESS);
}

void	destroy(t_fdf *fdf)
{
	free_array(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_image(fdf->mlx, fdf->ui->intro);
	mlx_destroy_image(fdf->mlx, fdf->ui->iso_panel);
	mlx_destroy_image(fdf->mlx, fdf->ui->ortho_panel);
	mlx_destroy_window(fdf->mlx, fdf->win);
}

void	free_array(int **array)
{
	int	i;

	i = -1;
	while (*(array + ++i))
		free(*(array + i));
	free(array);
}
