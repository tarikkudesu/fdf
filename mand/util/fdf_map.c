/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:38:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/18 18:17:14 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	get_value(int i, int j, t_fdf *fdf, char **line)
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

int	*get_row(t_fdf *fdf, char *line, int j)
{
	int		*row;
	int		i;

	row = malloc(sizeof(int) * fdf->width);
	if (!row)
		return (NULL);
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

int	**fill_map(t_fdf *fdf, int fd, int **map)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < fdf->height)
	{
		line = get_next_line(fd);
		if (!line)
			(free_array(map), close(fd), \
			ft_putendl_fd(ERR_READ, 2), exit(EXIT_FAILURE));
		*(map + i) = get_row(fdf, line, i);
		if (!*(map + i))
			(free_array(map), close(fd), \
			ft_putendl_fd(ERR_MAL, 2), exit(EXIT_FAILURE));
		free(line);
	}
	return (map);
}

int	**get_map(t_fdf *fdf, char *file_name)
{
	int		**map;
	int		fd;

	map = malloc(sizeof(int *) * (fdf->height));
	if (!map)
		(perror(ERR_MAL), exit(EXIT_FAILURE));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		(free(map), perror(ERR_OPEN), exit(EXIT_FAILURE));
	map = fill_map(fdf, fd, map);
	close(fd);
	return (map);
}
