#include"fractol.h"

void render_julia(t_data *img)
{
    double cr = -0.8;  // 固定 Julia 集的参数 c = cr + ci·i
    double ci = 0.156;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double zr = scale(x, 0, WIDTH, -2.0, 2.0);
            double zi = scale(y, 0, HEIGHT, 2.0, -2.0); // 注意虚部从上到下是反向的

            int iter = 0;
            while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
            {
                double tmp = zr * zr - zi * zi + cr;
                zi = 2.0 * zr * zi + ci;
                zr = tmp;
                iter++;
            }

            int color = (iter == MAX_ITER) ? 0x000000 : (iter * 255 / MAX_ITER) << 16;
            my_mlx_pixel_put(img, x, y, color);
        }
    }
}
