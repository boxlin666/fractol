#include"fractol.h"

void render_mandelbrot(t_data *img)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double re = scale(x, 0, WIDTH, -2.0, 1.0);
            double im = scale(y, 0, HEIGHT, -1.5, 1.5);
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

/*
void generate_mandelbrot(int width, int height, int max_iter) {
    for (int px = 0; px < width; px++) {
        for (int py = 0; py < height; py++) {
            // 将像素坐标映射到复数平面
            double x0 = map(px, 0, width, -2.0, 1.0);  // 实部范围 [-2, 1]
            double y0 = map(py, 0, height, -1.5, 1.5); // 虚部范围 [-1.5, 1.5]
            double x = 0, y = 0;
            int iter = 0;

            // 迭代计算 Zn+1 = Zn² + C
            while (x*x + y*y <= 4 && iter < max_iter) {
                double temp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = temp;
                iter++;
            }

            // 根据迭代次数着色
            draw_pixel(px, py, color(iter, max_iter));
        }
    }
}*/