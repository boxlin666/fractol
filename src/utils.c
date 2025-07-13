/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:32:33 by helin             #+#    #+#             */
/*   Updated: 2025/07/12 21:00:20 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double	map(int value, t_range src, t_range dst)
{
	return (dst.min + (value - src.min) * (dst.max - dst.min) / (src.max
			- src.min));
}

double	scale(double value, t_range screen, t_range complex)
{
	return (complex.min + (value - screen.min) * (complex.max - complex.min)
		/ (screen.max - screen.min));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_shifted_color(int iter, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	iter = (iter + shift) % max_iter;
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
