/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:00:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/19 11:22:11 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf_bonus.h"

void	null_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->map = NULL;
	fdf->ui = NULL;
	fdf->a = NULL;
	fdf->b = NULL;
}

void	null_ui(t_ui *ui)
{
	ui->intro = NULL;
	ui->iso_panel = NULL;
	ui->ortho_panel = NULL;
}

int	exit_program(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	if (fdf->map)
		free_array(fdf->map);
	if (fdf->color_map)
		free_array(fdf->color_map);
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->ui->intro)
		mlx_destroy_image(fdf->mlx, fdf->ui->intro);
	if (fdf->ui->iso_panel)
		mlx_destroy_image(fdf->mlx, fdf->ui->iso_panel);
	if (fdf->ui->ortho_panel)
		mlx_destroy_image(fdf->mlx, fdf->ui->ortho_panel);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(EXIT_SUCCESS);
}

void	destroy(t_fdf *fdf)
{
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->ui->intro)
		mlx_destroy_image(fdf->mlx, fdf->ui->intro);
	if (fdf->ui->iso_panel)
		mlx_destroy_image(fdf->mlx, fdf->ui->iso_panel);
	if (fdf->ui->ortho_panel)
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
