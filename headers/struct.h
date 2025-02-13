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
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

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
	bool	zoom_in;
	bool	zoom_out;
	bool	esc;
	bool	rx;
	bool	rrx;
	bool	ry;
	bool	rry;
	bool	rz;
	bool	rrz;
	bool	ez;
	bool	dz;
	bool	t;
	bool	f;
	bool	r;
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
	char	*__addr;
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
    t_heap  	*heap;
    t_map   	**map;
    int     	height;
    int     	width;
	t_angles	angles;
    t_image 	image;
    t_image 	intro;
    t_image 	ortho;
    t_image 	iso;
	t_keys		keys;
    t_mlx   	mlx;
    int     	max;
    int     	min;
	bool		pressed;

	bool		isoView;

	float		alpha;
	float		tetha;
	float		gamma;
	int			zoom;
	float		z_incr;
	int			x_translate;
	int			y_translate;

	t_map		a;
	t_map		b;
	int			x;
	int			y;
};

#endif // STRUCT_H_