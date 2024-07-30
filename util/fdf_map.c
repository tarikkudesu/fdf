/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:38:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/30 12:47:21 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

static int	get_value(int i, int j, t_fdf *fdf, char **line)
{
	int	value;

	value = ft_atoi(*line);
	while (**line && ft_isdigit(**line))
		(*line)++;
	if (**line == ',')
	{
		if (!fdf->colors)
			fdf->colors = 1;
		(*line)++;
		fdf->color_map[j][i] = ft_atoi_base(*line);
	}
	while (**line && **line != ' ')
		(*line)++;
	while (**line && **line == ' ')
		(*line)++;
	return (value);
}

static int	*get_row(t_fdf *fdf, char *line, int j)
{
	int		*row;
	int		i;

	row = talloc(sizeof(int) * fdf->width);
	i = -1;
	while (*line && *line == ' ')
		line++;
	while (++i < fdf->width)
	{
		*(row + i) = get_value(i, j, fdf, &line);
		if (*(row + i) > fdf->max)
			fdf->max = *(row + i);
		if (*(row + i) < fdf->min)
			fdf->min = *(row + i);
	}
	return (row);
}

static void	fill_map(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		line = get_next_line(fd);
		if (!line)
			(close(fd), putendl_fd(ERR_READ, 2), exit(EXIT_FAILURE));
		*(fdf->map + i) = get_row(fdf, line, i);
	}
}

void get_map(t_fdf *fdf, char *file_name)
{
	int		fd;

	fdf->map = talloc(sizeof(int *) * (fdf->height));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		terror(ERR_OPEN);
	fill_map(fdf, fd);
	if (!fdf->colors)
		init_color_map_grediant(fdf);
	close(fd);
}
