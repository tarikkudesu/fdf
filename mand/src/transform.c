/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/21 09:49:48 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a->x;
	fdf->a->x = (tmp - fdf->a->y) * cos(0.523599);
	fdf->a->y = (tmp + fdf->a->y) * sin(0.523599) - fdf->a->z;
	tmp = fdf->b->x;
	fdf->b->x = (tmp - fdf->b->y) * cos(0.523599);
	fdf->b->y = (tmp + fdf->b->y) * sin(0.523599) - fdf->b->z;
}

void	set_coordinnates(t_fdf *fdf)
{
	fdf->a->x *= (WIDTH / fdf->width) / 2;
	fdf->b->x *= (WIDTH / fdf->width) / 2;
	fdf->a->y *= (WIDTH / fdf->width) / 2;
	fdf->b->y *= (WIDTH / fdf->width) / 2;
	fdf->a->z *= fdf->z_zoom;
	fdf->b->z *= fdf->z_zoom;
	isometric(fdf);
	fdf->a->x += WIDTH / 2;
	fdf->b->x += WIDTH / 2;
	fdf->a->y += HEIGHT / 2;
	fdf->b->y += HEIGHT / 2;
}
