/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:17:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/23 09:41:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define MLX_XPM	"Error : mlx_xpm_file_to_image error"
# define ERR_ARG	"Error : Wrong number of arguments"
# define MLX_ADD	"Error : mlx_get_data_addr error"
# define ERR_OPEN	"Error : Error opening the file"
# define ERR_READ	"Error : Error reading the file"
# define MLX_WIN	"Error : mlx_new_window error"
# define MLX_IMG	"Error : mlx_new_image error"
# define ERR_FILE	"Error : Wrong file format"
# define MLX_INIT	"Error : mlx_init error"
# define ERR_MAL	"Error : malloc error"
# define ERR_EMTY	"Error : empty file"
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

typedef struct s_fdf	t_fdf;
typedef struct s_img	t_img;
typedef struct s_ui		t_ui;
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
	int		colors;
	int		**color_map;
	float	alpha;
	float	tetha;
	float	gamma;
	int		iso;
	int		max;
	int		min;
	int		zoom;
	int		pressed;
	int		x;
	int		y;
	float	z_incr;
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
	int		color;
};

struct s_p
{
	int		w;
	int		h;
};

#endif
