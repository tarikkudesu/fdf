#ifndef STRUCT_H_
#define STRUCT_H_

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_fdf    t_fdf;
typedef struct s_map    t_map;
typedef struct s_mlx	t_mlx;
typedef struct s_keys	t_keys;
typedef struct s_heap	t_heap;
typedef struct s_color	t_color;
typedef struct s_angles	t_angles;
typedef enum e_hooks    t_hooks;
typedef struct s_image	t_image;

enum e_hook
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

struct s_keys
{
	bool	space;
	bool	right;
	bool	down;
	bool	left;
	bool	up;
	bool	esc;
	bool	rx;
	bool	rrx;
	bool	ry;
	bool	rry;
	bool	rz;
	bool	rrz;
	bool	ez;
	bool	dz;
};

struct s_map
{
    int             x;
    int             y;
    int             z;
    unsigned int    color;
};

struct s_mlx
{
	void	*__mlx;
	void	*__win;
	void	*__iso;
	void	*__ortho;
	void	*__intro;
};

struct s_image
{
	void	*__img;
	int		*__addr;
	int		pixel_bits;
	int		line_bytes;
	int		width;
	int		height;
	int		endian;
};

struct s_angles
{
	double	alpha;
	double	tetha;
	double	gamma;
};

struct	s_color
{
	int	red;
	int	green;
	int	blue;
};

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};

struct s_fdf
{
    t_map   	**map;
    int     	height;
    int     	width;
    t_heap  	*heap;
    t_image 	image;
	t_angles	angles;
	t_keys		keys;
    t_mlx   	mlx;
    int     	max;
    int     	min;
	bool		pressed;
};

#endif // STRUCT_H_