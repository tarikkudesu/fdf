/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:09:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/07 17:51:40 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define ERR_ARG	"Wrong number of arguments :\n"
# define MLX_ADD	"mlx_get_data_addr error :\n"
# define ERR_OPEN	"Error opening the file :\n"
# define ERR_READ	"Error reading the file :\n"
# define MLX_WIN	"mlx_new_window error :\n"
# define MLX_IMG	"mlx_new_image error :\n"
# define MLX_INIT	"mlx_init error :\n"
# define ERR_MAL	"malloc error :\n"
# define ERR_NAME	"Invalid map :\n"
# define ERR_EMTY	"empty file :\n"
# define MAIN_COLOR	"0x0A261E"
# define LINE_COLOR	"0x76EFF0"
# define ANGLE		0.523599
# define WIDTH		1920
# define HEIGHT		1080
# define ESC		53
# define ZOOM_IN	69
# define ZOOM_OUT	78
# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define INCR_Z		91
# define DECR_Z		84
# define R_X		0
# define RR_X		1
# define R_Z		6
# define RR_Z		7
# define R_Y		12
# define RR_Y		13

typedef struct s_fdf	t_fdf;
typedef struct s_img	t_img;
typedef struct s_ui		t_ui;
typedef struct s_line	t_line;
typedef struct s_point	t_point;

struct s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		**color_map;
	int		color;
	float	alpha;
	float	tetha;
	float	gamma;
	int		zoom;
	int		z_zoom;
	float	x_offset;
	float	y_offset;
	void	*mlx;
	void	*win;
	t_img	*img;
	t_point	*a;
	t_point	*b;
	t_ui	*ui;
};

struct s_ui
{
	void	*panel;
	void	*intro;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
};

struct s_point
{
	int	x;
	int	y;
	int	z;	
};

// remove this
# include <stdio.h>


/* FUNCTIONS */
void		my_mlx_pixel_put(int x, int y, t_fdf *fdf);
void		draw_line(t_fdf *fdf);
void		rotate_z(t_fdf *fdf);
void		rotate_y(t_fdf *fdf);
void		rotate_x(t_fdf *fdf);
void		isometric(t_fdf *fdf);
void		set_coordinnates(t_fdf *fdf);
void 		print_color_map(t_fdf *fdf);
void 		print_map(t_fdf *fdf);
void		print_it(t_fdf *fdf);
int			handle_key(int key, void *f);

void		my_mlx_pixel_put(int x, int y, t_fdf *fdf);
void		interface(t_fdf *fdf);
float		max_value(float x, float y);
float		abs_float_value(float x);
void		draw_map(t_fdf *fdf);
void		design_img(t_fdf *fdf);
void		fill_image(t_fdf *fdf);
void		make_it_3d(t_fdf *fdf);
int			*get_row(t_fdf *fdf, char *line);
void		get_color_row(t_fdf *fdf, char *line, int j);
int			**fill_map(t_fdf *fdf, int fd, int **map);
int			**get_map(t_fdf *fdf, char *file_name);
int			**init_color_map(t_fdf *fdf);
int			ft_tolower(int c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
int			ft_atoi_base(char *line);
void		read_file(char *file_name, t_fdf *fdf);
int			get_width(char *file_name);
int			word_count(char *line);
int			get_height(char *file_name);
int			check_filename(char *s);
void		free_struct(t_fdf *fdf);
void		free_array(int **array);
int			ft_atoi_base(char *line);
int			ft_atoi(const char *str);

/* GET_NEXT_LINE */
size_t		gn_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*gn_strchr(const char *s);
char		*gn_strjoin(char *s1, char *s2);
char		*ft_after_nl(char *stat);
char		*ft_before_nl(char *stat);
char		*read_to_nl(char *stat, int fd);
char		*get_next_line(int fd);

/* LIBFT */
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);

#endif
