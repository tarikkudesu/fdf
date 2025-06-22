#include "../headers/fdf.h"
#include <math.h>

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


void my_mlx_pixel(int x, int y, unsigned int color, t_fdf *fdf)
{
    char *addr;
    int pixel;

    addr = fdf->image.__addr;
    pixel = y * fdf->image.line_bytes + x * 4;
    if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
    {
		addr[pixel + 0] = (color >> 0 & 255);
        addr[pixel + 1] = (color >> 8 & 255);
        addr[pixel + 2] = (color >> 16 & 255);
        addr[pixel + 3] = (color >> 24 & 255);
    }
}

void draw_circle(t_fdf *fdf) {
    int radius = fdf->zoom * 0.1;
	for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
				my_mlx_pixel(fdf->a.x + x, fdf->a.y + y, fdf->a.color, fdf);
            }
        }
    }
    for (int angle = 0; angle < 360; angle++) {
        double rad = angle * M_PI / 180.0;
        int x = fdf->a.x + (int)round(radius * cos(rad));
        int y = fdf->a.y + (int)round(radius * sin(rad));
        my_mlx_pixel(x, y, fdf->a.color, fdf);
    }
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
				fdf->a.z *= fdf->z_incr;
				fdf->b.z *= fdf->z_incr;
                set_coordinnates(fdf);
                draw_line(fdf);
            }
            if (y + 1 < fdf->height)
            {
				fdf->a = fdf->map[y][x];
                fdf->b = fdf->map[y + 1][x];
				fdf->a.z *= fdf->z_incr;
				fdf->b.z *= fdf->z_incr;
                set_coordinnates(fdf);
                draw_line(fdf);
            }
			draw_circle(fdf);
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