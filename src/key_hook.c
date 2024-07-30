/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/30 15:46:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_down(int key, void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	if (key == ESC)
		exit_program(fdf);

	if (key == SPACE && fdf->intro == true)
		fdf->intro = false;
	if (key == ZOOM_IN)
		fdf->keys.zoom_in = true;
	if (key == ZOOM_OUT)
		fdf->keys.zoom_out = true;
	if (key == RIGHT)
		fdf->keys.right = true;
	if (key == LEFT)
		fdf->keys.left = true;
	if (key == UP)
		fdf->keys.up = true;
	if (key == DOWN)
		fdf->keys.down = true;
	if (key == R_X)
		fdf->keys.rx = true;
	if (key == RR_X)
		fdf->keys.rrx = true;
	if (key == R_Z)
		fdf->keys.rz = true;
	if (key == RR_Z)
		fdf->keys.rrz = true;
	if (key == R_Y)
		fdf->keys.ry = true;
	if (key == RR_Y)
		fdf->keys.rry = true;
	if (key == INCR_Z)
		fdf->keys.ezup = true;
	if (key == DECR_Z)
		fdf->keys.ezdown = true;
	if (key == F_VIEW)
		fdf->keys.f = true;
	if (key == T_VIEW)
		fdf->keys.t = true;
	if (key == R_VIEW)
		fdf->keys.r = true;

	// if (key == ZOOM_IN || key == ZOOM_OUT)
	// 	zoom(key, fdf);
	// if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
	// 	translate(key, fdf);
	// if (key == R_X || key == RR_X || key == R_Z || key == RR_Z \
	// || key == R_Y || key == RR_Y)
	// 	rotate(key, fdf);
	// if (key == INCR_Z || key == DECR_Z)
	// 	elevate(key, fdf);
	// if (!fdf->iso && (key == F_VIEW || key == T_VIEW || key == R_VIEW))
		// orthographic(key, fdf);
	return (0);
}

int	key_up(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ZOOM_IN)
		fdf->keys.zoom_in = false;
	if (key == ZOOM_OUT)
		fdf->keys.zoom_out = false;
	if (key == RIGHT)
		fdf->keys.right = false;
	if (key == LEFT)
		fdf->keys.left = false;
	if (key == UP)
		fdf->keys.up = false;
	if (key == DOWN)
		fdf->keys.down = false;
	if (key == R_X)
		fdf->keys.rx = false;
	if (key == RR_X)
		fdf->keys.rrx = false;
	if (key == R_Z)
		fdf->keys.rz = false;
	if (key == RR_Z)
		fdf->keys.rrz = false;
	if (key == R_Y)
		fdf->keys.ry = false;
	if (key == RR_Y)
		fdf->keys.rry = false;
	if (key == INCR_Z)
		fdf->keys.ezup = false;
	if (key == DECR_Z)
		fdf->keys.ezdown = false;
	if (key == F_VIEW)
		fdf->keys.f = false;
	if (key == T_VIEW)
		fdf->keys.t = false;
	if (key == R_VIEW)
		fdf->keys.r = false;
	return (0);
}
