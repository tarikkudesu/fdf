/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:14:41 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 15:30:38 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf_bonus.h"

int	check_filename(char *s)
{
	int	i;

	if (!*s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	i--;
	while (*(s + i) != '.' && i >= -1)
		i--;
	if (i == -1)
		return (0);
	if (!ft_strcmp(s + i, ".fdf"))
		return (1);
	return (0);
}

int	get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
		(ft_putstr_fd(ERR_OPEN, 2), exit(EXIT_FAILURE));
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close (fd);
			return (height);
		}
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	word_count(char *line)
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

int	get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
		(ft_putstr_fd(ERR_OPEN, 2), exit(EXIT_FAILURE));
	width = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (width);
	}
	width = word_count(line);
	(free(line), close(fd));
	return (width);
}

void	read_file(char *file_name, t_fdf *fdf)
{
	fdf->height = get_height(file_name);
	fdf->width = get_width(file_name);
	if (!fdf->height || !fdf->width)
		(ft_putstr_fd(ERR_EMTY, 2), exit(EXIT_FAILURE));
}
