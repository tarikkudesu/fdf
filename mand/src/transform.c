/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 20:46:00 by tamehri          ###   ########.fr       */
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
	fdf->a->x *= fdf->zoom;
	fdf->b->x *= fdf->zoom;
	fdf->a->y *= fdf->zoom;
	fdf->b->y *= fdf->zoom;
	fdf->a->z *= fdf->zoom;
	fdf->b->z *= fdf->zoom;
	isometric(fdf);
	fdf->a->x += fdf->x_offset;
	fdf->b->x += fdf->x_offset;
	fdf->a->y += fdf->y_offset;
	fdf->b->y += fdf->y_offset;
}
