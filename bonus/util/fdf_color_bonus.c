/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:57:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/20 13:34:22 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf_bonus.h"

int	**init_color_map(t_fdf *fdf)
{
	int		**color_map;
	int		i;
	int		j;

	i = -1;
	j = -1;
	color_map = malloc(sizeof(int *) * fdf->height);
	if (!color_map)
		(perror(ERR_MAL), exit(EXIT_FAILURE));
	while (++i < fdf->height)
	{
		j = -1;
		*(color_map + i) = malloc(sizeof(int) * fdf->width);
		if (!*(color_map + i))
			(free_array(fdf->color_map), perror(ERR_MAL), exit(EXIT_FAILURE));
		while (++j < fdf->width)
			*(*(color_map + i) + j) = 0x76EFF0;
	}
	return (color_map);
}

int	get_color(float normalized_z, int max_color, int min_color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	b = ((min_color >> 0) & 255) + (((max_color >> 0) & 255) \
	- ((min_color >> 0) & 255)) * normalized_z;
	g = ((min_color >> 8) & 255) + (((max_color >> 8) & 255) \
	- ((min_color >> 8) & 255)) * normalized_z;
	r = ((min_color >> 16) & 255) + (((max_color >> 16) & 255) \
	- ((min_color >> 16) & 255)) * normalized_z;
	a = ((min_color >> 24) & 255) + (((max_color >> 24) & 255) \
	- ((min_color >> 24) & 255)) * normalized_z;
	return (a << 24 | r << 16 | g << 8 | b);
}

void	init_color_map_grediant(t_fdf *fdf)
{
	int		i;
	int		j;
	float	normalized_z;

	i = -1;
	j = -1;
	normalized_z = 0;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (fdf->max != fdf->min)
				normalized_z = perc(fdf->min, fdf->max, fdf->map[i][j]);
			fdf->color_map[i][j] = get_color(normalized_z, 0xa7ff83, 0x76EFF0);
		}
	}
}
