/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:43 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 11:06:50 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stat[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	stat[fd] = read_to_nl(stat[fd], fd);
	if (!stat[fd])
		return (NULL);
	line = ft_before_nl(stat[fd]);
	stat[fd] = ft_after_nl(stat[fd]);
	return (line);
}

char	*read_to_nl(char *stat, int fd)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (2));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!gn_strchr(stat) && bytes)
	{
		bytes = read(fd, buff, 1);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		*(buff + bytes) = '\0';
		stat = gn_strjoin(stat, buff);
	}
	free(buff);
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
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
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
	{
		free(stat);
		return (NULL);
	}
	line = malloc(sizeof(char) * (gn_strlen(stat + i) + 1));
	if (!line)
		return (free(stat), NULL);
	i++;
	j = 0;
	while (*(stat + i))
		*(line + j++) = *(stat + i++);
	*(line + j) = '\0';
	return (free(stat), line);
}
