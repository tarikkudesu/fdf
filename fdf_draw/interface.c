/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:57:17 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/04 10:31:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	draw_square(int x, int y, int h, int w, t_fdf *fdf)
// {
// 	int	*addr;
// 	int i;
// 	int j;

// 	addr = (int *)fdf->img->addr;
// 	j = y;
// 	while (j <= y + h)
// 	{
// 		i = x;
// 		while (i <= x + w)
// 		{
// 			addr[i * WIDTH + j] = 0xFFFFFF;
// 			i++;
// 		}
// 		j++;
// 	}
	
// }

void	interface(t_fdf *fdf)
{
	int	i;
	int	j;
	int	*addr;

	i = 99;
	addr = (int *)fdf->img->addr;
	while (++i <= 980)
	{
		j = 99;
		while (++j <= 400)
			addr[i * WIDTH + j] = 0x132F32;
	}
	// draw_square(120, 120, 40, 15, fdf);
	// draw_square(120, 120, 15, 80, fdf);
	// draw_square(150, 120, 30, 15, fdf);
	
	// draw_square(160, 160, 30, 15, fdf);
	// draw_square(180, 160, 30, 15, fdf);
	// draw_square(120, 180, 15, 80, fdf);
}