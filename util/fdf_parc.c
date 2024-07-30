/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:14:41 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/30 12:54:16 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

void	check_filename(char *s)
{
	int	i;

	if (!*s)
		terror(ERR_FILE);
	i = 0;
	while (*(s + i))
		i++;
	i--;
	while (*(s + i) != '.' && i >= -1)
		i--;
	if (i == -1)
		terror(ERR_FILE);
	if (ft_strcmp(s + i, ".fdf"))
		terror(ERR_FILE);
}

static int	get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
		(perror(ERR_OPEN), exit(EXIT_FAILURE));
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close (fd), height);
		height++;
	}
	return (close(fd), height);
}

static int	word_count(char *line)
{
	int	i;

	i = 0;
	while (*line && *line != '\n')
	{
		while (*line && *line != '\n' && *line == ' ')
			line++;
		if (*line && *line != '\n')
		{
			i++;
			while (*line && *line != '\n' && *line != ' ')
				line++;
		}
	}
	return (i);
}

static int	get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
		(perror(ERR_OPEN), exit(EXIT_FAILURE));
	width = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), width);
	width = word_count(line);
	return (close(fd), width);
}

void	read_file(char *file_name, t_fdf *fdf)
{
	fdf->width = get_width(file_name);
	fdf->height = get_height(file_name);
	if (!fdf->height || !fdf->width)
		terror(ERR_EMTY);
}
