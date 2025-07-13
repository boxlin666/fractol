/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:43:28 by helin             #+#    #+#             */
/*   Updated: 2025/07/13 17:25:05 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double re, double im)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + re;
		zi = 2.0 * zr * zi + im;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	compute_and_draw_pixel(t_data *img, int x, int y)
{
	double	re;
	double	im;
	int		iter;
	int		color;

	re = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
	im = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;
	iter = mandelbrot_iterations(re, im);
	color = get_shifted_color(iter, MAX_ITER, 0.2);
	my_mlx_pixel_put(img, x, y, color);
}

void	render_mandelbrot(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			compute_and_draw_pixel(img, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
