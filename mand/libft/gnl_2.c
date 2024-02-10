/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:36:09 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 20:42:47 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

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
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
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
	if (!s1 || !s2)
		return (0);
	res = malloc((gn_strlen(s1) + gn_strlen(s2) + 1) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (s1 = NULL, NULL);
	}
	i = -1;
	while (*(s1 + ++i))
		*(res + i) = *(s1 + i);
	j = 0;
	while (*(s2 + j))
		*(res + i++) = *(s2 + j++);
	*(res + i) = '\0';
	free(s1);
	s1 = NULL;
	return (res);
}
