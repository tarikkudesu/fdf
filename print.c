/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:39:32 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/06 10:13:46 by tamehri          ###   ########.fr       */
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
	print_color_map(fdf);
	printMatrix(fdf, fdf->width / 2, fdf->height / 2);
	// print_map(fdf);
	// printf("zoom : %d\ncolor : %x\nx_offset : %d\ny_offset : %d\n", fdf->zoom, fdf->color, fdf->x_offset, fdf->y_offset);
}