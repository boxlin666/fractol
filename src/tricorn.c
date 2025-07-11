/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:33:03 by helin             #+#    #+#             */
/*   Updated: 2025/07/11 22:09:29 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn_iterations(double cr, double ci)
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
		tmp = zr * zr - zi * zi + cr;
		zi = -2.0 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	compute_and_draw_tricorn(t_data *img, int x, int y)
{
	double	cr;
	double	ci;
	int		iter;
	int		color;

	cr = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->offset_x;
	ci = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->offset_y;
	iter = tricorn_iterations(cr, ci);
	color = get_shifted_color(iter, img->max_iter, 3);
	my_mlx_pixel_put(img, x, y, color);
}

void	render_tricorn(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_and_draw_tricorn(img, x, y);
			x++;
		}
		y++;
	}
}
