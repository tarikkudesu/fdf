/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:04:37 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 11:36:44 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../src/fdf_bonus.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);

}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - '0';
		i++;
	}
	return (res * sign);
}

int	ft_atoi_base(char *line)
{
	int		result;
	char	c;

	while (*line && *line != ' ')
	{
		c = ft_tolower(*line);
		if (c >= '0' && c <= '9')
			result = result * 16 + (c - '0');
		else if (c >= 'a' && c <= 'f')
			result = result * 16 + (c - 'a' + 10);
		else
			break ;
		line++;
	}
	return (result);
}
