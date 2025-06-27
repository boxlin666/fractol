#include"fractol.h"

int	julia_iterations(double zr, double zi, double cr, double ci)
{
	double	tmp;
	int		iter = 0;

	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	compute_and_draw_julia(t_data *img, int x, int y, double cr, double ci)
{
	double	zr = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
	double	zi = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;
	int		iter = julia_iterations(zr, zi, cr, ci);
	int		color = get_shifted_color(iter, MAX_ITER, 0.2);

	my_mlx_pixel_put(img, x, y, color);
}

void	render_julia(t_data *img, double cr, double ci)
{
	int	x = 0;
	int	y = 0;

	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			compute_and_draw_julia(img, x, y, cr, ci);
			x++;
		}
		x = 0;
		y++;
	}
}
