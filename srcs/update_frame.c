#include "../headers/fdf.h"

void my_mlx_pixel_put(int x, int y, unsigned int color)
{
    t_fdf *fdf;
    int *addr;
    int pixel;

    fdf = getFdf(NULL);
    addr = (int *)fdf->image.__addr;
    pixel = y * fdf->image.line_bytes / 4 + x;
    if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
        addr[pixel] = color;
}

void fillWindow(t_fdf *fdf)
{
    int x;
    int *addr;

    x = -1;
    addr = (int *)fdf->image.__addr;
    while (++x < WIDTH * HEIGHT)
        addr[x] = BACKGROUND;
}

void drawMap(t_fdf *fdf)
{
    int x;
    int y;

    x = -1;
    while (++x < fdf->width)
    {
        y = -1;
        while (++y < fdf->height)
        {
            if (x + 1 < fdf->width)
            {
                fdf->a = fdf->map[y][x];
                fdf->b = fdf->map[y][x + 1];
                set_coordinnates(fdf);
                // printf("%d %d => %d %d\n", fdf->a.x, fdf->a.y, fdf->b.x, fdf->b.y);
                draw_line(fdf);
            }
            if (y + 1 < fdf->height)
            {
                fdf->a = fdf->map[y][x];
                fdf->b = fdf->map[y + 1][x];
                set_coordinnates(fdf);
                draw_line(fdf);
                // printf("%d %d => %d %d\n", fdf->a.x, fdf->a.y, fdf->b.x, fdf->b.y);
            }
        }
    }
}

int update_frame(t_fdf *fdf)
{
    fillWindow(fdf);
    update_hooks(fdf);
    drawMap(fdf);
    mlx_put_image_to_window(fdf->mlx.__mlx, fdf->mlx.__win, fdf->image.__img, 0, 0);
	if (fdf->isoView)
		mlx_put_image_to_window(fdf->mlx.__mlx, fdf->mlx.__win, fdf->iso.__img, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx.__mlx, fdf->mlx.__win, fdf->ortho.__img, 0, 0);
    return 0;
}