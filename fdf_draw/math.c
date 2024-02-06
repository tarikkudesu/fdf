/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:11:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/03 18:59:34 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	abs_float_value(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	max_value(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

