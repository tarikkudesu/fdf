/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:00:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/20 17:37:25 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	handle_key(int key, void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	if (key == ESC)
		exit_program(fdf);
	return (0);
}

int	exit_program(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	exit(EXIT_SUCCESS);
}

void	free_array(int **array)
{
	int	i;

	i = -1;
	while (*(array + ++i))
		free(*(array + i));
	free(array);
}
