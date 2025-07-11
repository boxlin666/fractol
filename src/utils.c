/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:32:33 by helin             #+#    #+#             */
/*   Updated: 2025/07/11 22:32:34 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double	map(int value, int min1, int max1, double min2, double max2)
{
	return (min2 + (value - min1) * (max2 - min2) / (max1 - min1));
}

double	scale(double value, double min_screen, double max_screen,
		double min_complex, double max_complex)
{
	return (min_complex + (value - min_screen) * (max_complex - min_complex)
		/ (max_screen - min_screen));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0xFFFFFF);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_psychedelic_color(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)max_iter;
	r = (int)(sin(0.16 * iter + 0) * 127 + 128);
	g = (int)(sin(0.16 * iter + 2) * 127 + 128);
	b = (int)(sin(0.16 * iter + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
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
