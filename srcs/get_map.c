# include "../headers/fdf.h"

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

int	get_value(t_map *mapElement, char **line)
{
	int	value;

	value = ft_atoi(*line);
	while (**line && ft_isdigit(**line))
		(*line)++;
	if (**line == ',')
	{
		(*line)++;
		mapElement->color = ft_atoi_base(*line);
		while (**line && **line != ' ')
			(*line)++;
	}
	else mapElement->color = 0;
	while (**line && **line == ' ')
		(*line)++;
	return (value);
}

void    getRow(t_fdf *fdf, char *line, int j)
{
	int		i;

	*(fdf->map + j) = malloc(sizeof(t_map) * fdf->width);
	i = -1;
	while (*line && *line == ' ')
		line++;
	while (++i < fdf->width)
	{
		(*(fdf->map + j) + i)->z = get_value(*(fdf->map + j) + i, &line);
        (*(fdf->map + j) + i)->x = i;
        (*(fdf->map + j) + i)->y = j;
		if ((*(fdf->map + j) + i)->z > fdf->max)
			fdf->max = (*(fdf->map + j) + i)->z;
		if ((*(fdf->map + j) + i)->z < fdf->min)
			fdf->min = (*(fdf->map + j) + i)->z;
	}
}

void    fillMap(t_fdf *fdf, int fd) {
    char    *line;
    int     i;

    i = -1;
    while (++i < fdf->height)
    {
        line = get_next_line(fd);
        if (!line)
            (close(fd), terror(ERR_READ));
        getRow(fdf, line, i);
    }
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
			if (fdf->map[i][j].color == 0)
			{
				if (fdf->max != fdf->min)
				normalized_z = perc(fdf->min, fdf->max, fdf->map[i][j].z);
				fdf->map[i][j].color = get_color(normalized_z, 0xa7ff83, 0x76EFF0);
			}
		}
	}
}

void    getMap( t_fdf *fdf, char *fileName ) {
    int fd;

	fd = open(fileName, O_RDONLY);
	if (-1 == fd)
		terror(ERR_OPEN);
    fdf->map = talloc(sizeof(t_map *) * fdf->height);
    fillMap(fdf, fd);
	init_color_map_grediant(fdf);
    close(fd);
}
