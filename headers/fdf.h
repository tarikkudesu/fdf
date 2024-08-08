#ifndef FDF_H_
#define FDF_H_

# include "struct.h"
# include "macros.h"

/* FUNCTIONS */
void	my_mlx_pixel_put(int x, int y, unsigned int color);
int	ft_atoi_base(char *line);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
int	mouse_press(int button, int x, int y, t_fdf *fdf);
int	mouse_move(int x, int y, t_fdf *fdf);
int	mouse_release(int button, int x, int y, t_fdf *fdf);
int	exit_program(t_fdf *fdf);
int update_frame( t_fdf *fdf );
int	key_down(int key, t_fdf *fdf);
int	key_up(int key, t_fdf *fdf);
void    initWindow( t_fdf *fdf );
void	putendl_fd(char *s, int fd);
int     terror( char *__err_message );
t_fdf   *getFdf( t_fdf *fdf );
void	*talloc( size_t __size );
void	clearheap(t_heap **node);
void	heap_addback(t_heap **lst, t_heap *new);
t_heap	*heap_new(void *content);
void    getMap( t_fdf *fdf, char *fileName );
void    initFdf( t_fdf *fdf, char *fileName );

#endif // FDF_H_