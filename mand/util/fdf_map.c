/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:38:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 20:42:30 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	*get_row(t_fdf *fdf, char *line)
{
	int		*row;
	int		i;

	row = malloc(sizeof(int) * fdf->width);
	if (!row)
		return (NULL);
	i = -1;
	while (++i < fdf->width)
	{
		*(row + i) = ft_atoi(line);
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
		*(map + i) = get_row(fdf, line);
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
