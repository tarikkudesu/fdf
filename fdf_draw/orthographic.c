/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthographic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:07 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/09 17:08:44 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

void	orthographic(int key, t_fdf *fdf)
{
	if (key == T_VIEW)
	{
		fdf->gamma = 0;
		fdf->tetha = 0;
		fdf->alpha = 0;
		
	}
	else if (key == R_VIEW)
	{
		fdf->gamma = 0;
		fdf->tetha = 0;
		fdf->alpha = 1.5708;
	}
	else
	{
		fdf->gamma = -1.5708;
		fdf->tetha = 1.5708;
		fdf->alpha = 0;
	}
}