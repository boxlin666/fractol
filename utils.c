#include "fractol.h"

double	map(int value, int min1, int max1, double min2, double max2)
{
	return (min2 + (value - min1) * (max2 - min2) / (max1 - min1));
}

// 将像素 (x, y) 映射为复数 c
double	scale(double value, double min_screen, double max_screen,
		double min_complex, double max_complex)
{
	return (min_complex + (value - min_screen) * (max_complex - min_complex)
		/ (max_screen - min_screen));
}

// 设置图像中的像素颜色
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}