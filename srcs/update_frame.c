# include "../headers/fdf.h"

void	my_mlx_pixel_put(int x, int y, unsigned int color)
{
	t_fdf	*fdf;
	int		*addr;
	int		pixel;

	fdf = getFdf(NULL);
	addr = (int *)fdf->image.__addr;
	pixel = y * fdf->image.line_bytes / 4 + x;
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		addr[pixel] = color;
}

void    fillWindow(t_fdf *fdf) {
    int x;

    x = -1;
    while (++x < WIDTH * HEIGHT)
        fdf->image.__addr[x] = BACKGROUND;
}

void    setPoint()
{

}

void    drawMap( t_fdf *fdf )
{
    int x;
    int y;

    x = -1;
    while (++x < fdf->width)
    {
        y = -1;
        while (++y < fdf->height)
        {

        }
    }
}

int update_frame( t_fdf *fdf ) {
    fillWindow(fdf);
    drawMap(fdf);
    mlx_put_image_to_window(fdf->mlx.__mlx, fdf->mlx.__win, fdf->image.__img, 0, 0);
    return 0;
}