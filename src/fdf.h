/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/30 15:02:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "struct.h"

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
void	putendl_fd(char *s, int fd);
float	perc(float c1, float c2, float c);
int		ft_tolower(int c);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
int		ft_atoi_base(char *line);

void	clearheap(t_heap **node);
void	heap_addback(t_fdf *fdf, t_heap *new);
t_heap	*heap_new(void *content);
t_fdf	*get_fdf(t_fdf *fdf);
void	*talloc(size_t __size);
void	terror(char *__err__message);

/* FUNCTIONS */
void	zoom(int key, t_fdf *fdf);
void	reset_view(t_fdf *fdf);
void	putendl_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);
int	ft_isdigit(int c);
void	draw_line(t_fdf *fdf);
void	draw_map(t_fdf *fdf);
int	mouse_release(int button, int x, int y, t_fdf *fdf);
int	mouse_move(int x, int y, void *param);
int	mouse_press(int button, int x, int y, void *param);
void	orthographic(int key, t_fdf *fdf);
void	isometric_view(t_fdf *fdf);
void	orthographic_view(t_fdf *fdf);
void	init_fdf(t_fdf *fdf, char *file_name);
int	key_down(int key, void *f);
int	key_up(int key, void *param);
void	rotate_z(t_fdf *fdf);
void	rotate_y(t_fdf *fdf);
void	rotate_x(t_fdf *fdf);
void	isometric(t_fdf *fdf);
void	set_coordinnates(t_fdf *fdf);
int	update_frame(void *param);
void	init_color_map(t_fdf *fdf);
int	get_color(float normalized_z, int max_color, int min_color);
void	init_color_map_grediant(t_fdf *fdf);
int	exit_program(void *f);
void get_map(t_fdf *fdf, char *file_name);
void	check_filename(char *s);
void	read_file(char *file_name, t_fdf *fdf);
int	ft_atoi_base(char *line);
int	ft_atoi(const char *str);
float	perc(float c1, float c2, float c);



#endif
