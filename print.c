/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:39:32 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/06 18:27:08 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void printMatrix(t_fdf *fdf, int x, int y)
{
    if (x < 0 || x > fdf->width || y < 0 || y > fdf->height) 
        return ;
	
    printf("%d ", fdf->map[y][x]);

    printMatrix(fdf, x - 1, y);
    printMatrix(fdf, x + 1, y);
	printf("\n");
    printMatrix(fdf, x, y - 1);
    printMatrix(fdf, x, y + 1);
}

void print_color_map(t_fdf *fdf)
{
	int i = 0;
	while(i < fdf->height) {
		int j = 0;
		while(j < fdf->width) {
			printf("0x%x\t", fdf->color_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void print_map(t_fdf *fdf)
{
	int i = 0;
	while(i < fdf->height) {
		int j = 0;
		while(j < fdf->width) {
			printf("%d ", fdf->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_it(t_fdf *fdf)
{
	printf("width : %d, height : %d\n", fdf->width, fdf->height);
	print_color_map(fdf);
	print_map(fdf);
}
