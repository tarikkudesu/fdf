# include "../headers/fdf.h"


size_t	gn_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = gn_strlen(s1);
	res = talloc((i + 1) * sizeof(char));
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

char	*gn_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*gn_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	res = talloc((gn_strlen(s1) + gn_strlen(s2) + 1) * sizeof(char));
	i = -1;
	while (*(s1 + ++i))
		*(res + i) = *(s1 + i);
	j = 0;
	while (*(s2 + j))
		*(res + i++) = *(s2 + j++);
	*(res + i) = '\0';
	s1 = NULL;
	return (res);
}

char	*read_to_nl(char *stat, int fd)
{
	char	*buff;
	int		bytes;

	buff = talloc(sizeof(char) * (2));
	bytes = 1;
	while (!gn_strchr(stat) && bytes)
	{
		bytes = read(fd, buff, 1);
		if (bytes == -1)
			return (NULL);
		*(buff + bytes) = '\0';
		stat = gn_strjoin(stat, buff);
	}
	return (stat);
}

char	*ft_before_nl(char *stat)
{
	char	*line;
	int		i;

	if (!*stat)
		return (NULL);
	i = 0;
	while (*(stat + i) && *(stat + i) != '\n')
		i++;
	line = talloc(sizeof(char) * i + 2);
	i = 0;
	while (*(stat + i) && *(stat + i) != '\n')
	{
		*(line + i) = *(stat + i);
		i++;
	}
	if (*(stat + i) == '\n')
		*(line + i++) = '\n';
	*(line + i) = '\0';
	return (line);
}

char	*ft_after_nl(char *stat)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (*(stat + i) && *(stat + i) != '\n')
		i++;
	if (!*(stat + i))
		return (NULL);
	line = talloc(sizeof(char) * (gn_strlen(stat + i) + 1));
	i++;
	j = 0;
	while (*(stat + i))
		*(line + j++) = *(stat + i++);
	*(line + j) = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	stat[fd] = read_to_nl(stat[fd], fd);
	if (!stat[fd])
		return (NULL);
	line = ft_before_nl(stat[fd]);
	stat[fd] = ft_after_nl(stat[fd]);
	return (line);
}
