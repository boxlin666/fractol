/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:22:03 by helin             #+#    #+#             */
/*   Updated: 2025/07/25 13:18:36 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iterations(double zr, double zi, double cr, double ci)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	compute_and_draw_julia(t_data *img, int x, int y)
{
	double	zr;
	double	zi;
	int		iter;
	int		color;

	zr = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
	zi = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;
	iter = julia_iterations(zr, zi, img->c_re, img->c_im);
	color = get_shifted_color(iter, MAX_ITER, img->color_shift);
	my_mlx_pixel_put(img, x, y, color);
}

void	render_julia(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			compute_and_draw_julia(img, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
