#include "mlx.h"
#include <math.h>
#include "fractol.h"

// 渲染 Mandelbrot 分形


int main(void)
{
    t_data img;

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Mandelbrot");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

    render_mandelbrot(&img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
    return (0);
}
