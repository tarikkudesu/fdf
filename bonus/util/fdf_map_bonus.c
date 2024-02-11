/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:38:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/11 16:18:25 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf_bonus.h"

int	**init_color_map(t_fdf *fdf)
{
	int		**color_map;
	int 	i;
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
		*(row + i) = ft_atoi(line);
		while (*line && ft_isdigit(*line))
			line++;
		if (*line == ',')
		{
			line++;
			fdf->color_map[j][i] = ft_atoi_base(line);
		}
		while (*line && *line != ' ')
			line++;
		while (*line && *line == ' ')
			line++;
	}
	return (row);
}

int	**fill_map(t_fdf *fdf, int fd, int **map)
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
