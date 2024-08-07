# include "../headers/fdf.h"

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
	}
	while (**line && **line != ' ')
		(*line)++;
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

void    getMap( t_fdf *fdf, char *fileName ) {
    int fd;

	fd = open(fileName, O_RDONLY);
	if (-1 == fd)
		terror(ERR_OPEN);
    fdf->map = talloc(sizeof(t_map *) * fdf->height);
    fillMap(fdf, fd);
    close(fd);
}
