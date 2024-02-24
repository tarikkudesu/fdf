/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/23 09:41:03 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "/usr/local/include/mlx.h"
# include "fdf_struct.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

/* HELP_FUNCTIONS */
char	*gn_strjoin(char *s1, char *s2);
char	*gn_strchr(const char *s);
char	*ft_strdup(const char *s1);
size_t	gn_strlen(const char *s);
char	*ft_after_nl(char *stat);
char	*ft_before_nl(char *stat);
char	*read_to_nl(char *stat, int fd);
char	*get_next_line(int fd);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
float	perc(float c1, float c2, float c);
int		ft_tolower(int c);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
int		ft_atoi_base(char *line);

/* FUNCTIONS */
int		handle_mouse_release(int button, int x, int y, t_fdf *fdf);
int		handle_mouse_move(int x, int y, void *param);
void	orthographic(int key, t_fdf *fdf);
void	reset_view(t_fdf *fdf);
void	isometric_view(t_fdf *fdf);
void	orthographic_view(t_fdf *fdf);
int		handle_mouse(int button, int x, int y, void *param);
void	translate(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	elevate(int key, t_fdf *fdf);
int		handle_key(int key, void *f);
void	my_mlx_pixel_put_big(int x, int y, t_fdf *fdf);
void	my_mlx_pixel_put_less(int x, int y, t_fdf *fdf);
void	slope_less_then_one(int p, int dx, int dy, t_fdf *fdf);
void	slope_bigger_than_one(int p, int dx, int dy, t_fdf *fdf);
void	draw_line(t_fdf *fdf);
void	rotate_z(t_fdf *fdf);
void	rotate_y(t_fdf *fdf);
void	rotate_x(t_fdf *fdf);
void	isometric(t_fdf *fdf);
void	set_coordinnates(t_fdf *fdf);
void	set_point(int x, int y, t_fdf *fdf);
void	design_img(t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	fill_image(t_fdf *fdf);
void	panel(t_fdf *fdf);
void	null_fdf(t_fdf *fdf);
void	null_ui(t_ui *ui);
void	make_it_3d(t_fdf *fdf);
void	init_fdf(t_fdf *fdf, char *file_name);
int		exit_program(void *f);
void	free_array(int **array);
int		**init_color_map(t_fdf *fdf);
int		get_color(float normalized_z, int max_color, int min_color);
void	init_color_map_grediant(t_fdf *fdf);
int		get_value(int i, int j, t_fdf *fdf, char **line);
int		*get_row(t_fdf *fdf, char *line, int j);
int		**fill_map(t_fdf *fdf, int fd, int **map);
int		**get_map(t_fdf *fdf, char *file_name);
int		check_filename(char *s);
int		get_height(char *file_name);
int		word_count(char *line);
int		get_width(char *file_name);
void	read_file(char *file_name, t_fdf *fdf);

#endif
