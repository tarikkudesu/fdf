/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:00:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/30 11:58:39 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	exit_program(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(EXIT_SUCCESS);
}
