/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:17:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 15:27:24 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

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
# define WIDTH		1920
# define HEIGHT		1080

# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define ESC		53
# define ZOOM_IN	69
# define ZOOM_OUT	78
# define INCR_Z		91
# define DECR_Z		84
# define R_Z		89
# define RR_Z		92
# define R_Y		86
# define RR_Y		88
# define R_X		83
# define RR_X		85
# define T_VIEW		17
# define R_VIEW		15
# define F_VIEW		3
# define ISO		34
# define ORTH		31

typedef struct s_fdf	t_fdf;
typedef struct s_img	t_img;
typedef struct s_ui		t_ui;
typedef struct s_line	t_line;
typedef struct s_point	t_point;
typedef struct s_p		t_p;

struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_ui	*ui;
	t_point	*a;
	t_point	*b;
	int		width;
	int		height;
	int		**map;
	int		color;
	float	alpha;
	float	tetha;
	float	gamma;
	int		iso;
	int		zoom;
	float	z_zoom;
	int		x_offset;
	int		y_offset;
	int		x_translate;
	int		y_translate;
};

struct s_ui
{
	void	*iso_panel;
	void	*ortho_panel;
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
	int		x;
	int		y;
	float	z;
};

struct s_p
{
	int		w;
	int		h;
};

#endif
