#include"fractol.h"

void render_mandelbrot(t_data *img)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            // 把像素坐标映射到复平面
            double re = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
            double im = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;

            double zr = 0, zi = 0;
            int iter = 0;

            while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
            {
                double tmp = zr * zr - zi * zi + re;
                zi = 2.0 * zr * zi + im;
                zr = tmp;
                iter++;
            }

            int color = iter == MAX_ITER ? 0x000000 : (iter * 255 / MAX_ITER) << 16;
            my_mlx_pixel_put(img, x, y, color);
        }
    }
}
