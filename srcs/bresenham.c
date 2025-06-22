#include "../headers/fdf.h"

float perc(float c1, float c2, float c)
{
    if (c1 != c2)
        return ((c - c1) / (c2 - c1));
    return (0);
}

void my_mlx_pixel_put_big(int x, int y, t_fdf *fdf)
{
    char *addr;
    int pixel;

    addr = fdf->image.__addr;
    pixel = y * fdf->image.line_bytes + x * 4;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
		for (int i = 0; i <= 4; i++) {
			int b = ((fdf->b.color >> i * 8) & 255);
			int a = ((fdf->a.color >> i * 8) & 255);
			addr[pixel + i] = a + (b - a) * perc(fdf->a.y, fdf->b.y, y);
		}
    }
}

void my_mlx_pixel_put_less(int x, int y, t_fdf *fdf)
{
    char *addr;
    int pixel;

    addr = fdf->image.__addr;
    pixel = y * fdf->image.line_bytes + x * 4;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
		for (int i = 0; i <= 4; i++) {
			int b = ((fdf->b.color >> i * 8) & 255);
			int a = ((fdf->a.color >> i * 8) & 255);
			addr[pixel + i] = a + (b - a) * perc(fdf->a.y, fdf->b.y, y);
		}
    }
}

void slope_less_then_one(int p, int dx, int dy, t_fdf *fdf)
{
    int i;
    int x;
    int y;

    i = -1;
    x = fdf->a.x;
    y = fdf->a.y;
    while (++i < abs(dx))
    {
        if (dx < 0)
            x -= 1;
        else
            x += 1;
        if (p < 0)
            p = p + 2 * abs(dy);
        else
        {
            if (dy < 0)
                y -= 1;
            else
                y += 1;
            p = p + 2 * abs(dy) - 2 * abs(dx);
        }
        my_mlx_pixel_put_less(x, y, fdf);
    }
}

void slope_bigger_than_one(int p, int dx, int dy, t_fdf *fdf)
{
    int i;
    int x;
    int y;

    i = -1;
    x = fdf->a.x;
    y = fdf->a.y;
    while (++i < abs(dy))
    {
        if (dy < 0)
            y -= 1;
        else
            y += 1;
        if (p < 0)
            p = p + 2 * abs(dx);
        else
        {
            if (dx < 0)
                x -= 1;
            else
                x += 1;
            p = p + 2 * abs(dx) - 2 * abs(dy);
        }
        my_mlx_pixel_put_big(x, y, fdf);
    }
}

void draw_line(t_fdf *fdf)
{
    int dx;
    int dy;

    dx = fdf->b.x - fdf->a.x;
    dy = fdf->b.y - fdf->a.y;
    my_mlx_pixel_put_less(fdf->a.x, fdf->a.y, fdf);
    if (abs(dx) > abs(dy))
        slope_less_then_one(2 * abs(dy) - abs(dx), dx, dy, fdf);
    else
        slope_bigger_than_one(2 * abs(dx) - abs(dy), dx, dy, fdf);
}
