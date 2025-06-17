#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

int key_hook(int keycode, t_data *img)
{
    printf("Keycode: %d\n", keycode);
    if (keycode == 65307) // macOS ESC
    {
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
    else if (keycode == 65362) // ↑
        img->offset_y -= 0.1 / img->zoom;
    else if (keycode == 65364) // ↓
        img->offset_y += 0.1 / img->zoom;
    else if (keycode == 65361) // ←
        img->offset_x -= 0.1 / img->zoom;
    else if (keycode == 65363) // →
        img->offset_x += 0.1 / img->zoom;
    else if (keycode == 65451) // +
        img->zoom *= 1.2;
    else if (keycode == 65453) // -
        img->zoom /= 1.2;

    render_mandelbrot(img);
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    return (0);
}

int mouse_hook(int button, int x, int y, t_data *img)
{
    if (button == 4 || button == 5) // 滚轮上下
    {
        double zoom_factor = (button == 4) ? 1.2 : 1 / 1.2;

        // 获取鼠标指向的复平面位置
        double mouse_re = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
        double mouse_im = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;

        // 更新 zoom
        img->zoom *= zoom_factor;

        // 缩放时让焦点保持在鼠标位置
        img->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH);
        img->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT);

        // 重绘
        render_mandelbrot(img);
        mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    }
    return (0);
}

int	mouse_click(int button, int x, int y, t_data *img)
{
	if (button == 1) // 鼠标左键按下
	{
		img->is_dragging = 1;
		img->last_x = x;
		img->last_y = y;
	}
	else if (button == 3) // 鼠标右键松开，或你可以检测释放事件
	{
		img->is_dragging = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *img)
{
	if (!img->is_dragging || (x == img->last_x && y == img->last_y))
		return (0);

    
	// 计算拖动差值
	int dx = x - img->last_x;
	int dy = y - img->last_y;

	// 更新视角偏移（随着拖动平移图像）
	img->offset_x -= (double)dx / (0.5 * img->zoom * WIDTH);
	img->offset_y -= (double)dy / (0.5 * img->zoom * HEIGHT);

	// 更新旧坐标
	img->last_x = x;
	img->last_y = y;

	// 重绘
	render_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);

	return (0);
}


int close_window(t_data *img)
{
    mlx_destroy_window(img->mlx, img->win);
    exit(0);
    return (0);
}

int main(void)
{
    t_data img;

    img.zoom = 1.0;
    img.offset_x = -0.5;
    img.offset_y = 0.0;
    img.max_iter = MAX_ITER;
    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Mandelbrot");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    mlx_hook(img.win, 2, 1L << 0, key_hook, &img); // 键盘按下
    mlx_hook(img.win, 17, 0, close_window, &img);  // 关闭窗口
    mlx_mouse_hook(img.win, mouse_hook, &img);
    mlx_mouse_hook(img.win, mouse_click, &img);      // 鼠标点击
    mlx_hook(img.win, 6, 1L << 6, mouse_move, &img); // 鼠标移动

    render_mandelbrot(&img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
    return (0);
}
