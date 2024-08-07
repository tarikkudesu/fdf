# include "../headers/fdf.h"

void	checkFilename(char *s)
{
	int	i;

	if (!*s)
		terror(ERR_EMTY);
	i = 0;
	while (*(s + i))
		i++;
	i--;
	while (*(s + i) != '.' && i >= -1)
		i--;
	if (i == -1 || ft_strcmp(s + i, ".fdf"))
		terror(ERR_FILE);
}

int	word_count(char *line) {
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

void    getDimensions(t_fdf *fdf, char *fileName) {
    char    *line;
    int     fd;

	fd = open(fileName, O_RDONLY);
	if (-1 == fd)
		terror(ERR_OPEN);
    line = get_next_line(fd);
    if (!line)
        (close(fd), terror(ERR_EMTY));
    fdf->width = word_count(line);
    fdf->height++;
    while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fdf->height++;
	}
    close(fd);
}

void    initFdf( t_fdf *fdf, char *fileName ) {
    checkFilename(fileName);
    getDimensions(fdf, fileName);
    getMap(fdf, fileName);
    printf("%d %d\n", fdf->width, fdf->height);
}
