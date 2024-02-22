/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:17:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/21 10:25:50 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define ERR_ARG	"Error : Wrong number of arguments"
# define MLX_ADD	"Error : mlx_get_data_addr error"
# define ERR_READ	"Error : Error reading the file"
# define MLX_WIN	"Error : mlx_new_window error"
# define MLX_IMG	"Error : mlx_new_image error"
# define ERR_FILE	"Error : Wrong file format"
# define MLX_INIT	"Error : mlx_init error"
# define ERR_MAL	"Error : malloc error"
# define ERR_EMTY	"Error : empty file"
# define ERR_OPEN	"Error"
# define WIDTH		1000
# define HEIGHT		1000
# define ESC		53

typedef struct s_fdf	t_fdf;
typedef struct s_img	t_img;
typedef struct s_point	t_point;

struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_point	*a;
	t_point	*b;
	int		width;
	int		height;
	int		**map;
	int		**color_map;
	int		colors;
	int		max;
	int		min;
	float	alpha;
	float	tetha;
	float	gamma;
	int		z_zoom;
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
	int	color;
};

#endif
