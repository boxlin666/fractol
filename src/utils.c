/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:32:33 by helin             #+#    #+#             */
/*   Updated: 2025/07/31 18:30:50 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

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

int	is_valid_float(const char *str)
{
	int	has_dot;

	has_dot = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_param(const char *flag, const char *value)
{
	if (!value)
		return (0);
	if (ft_strcmp(flag, "-zoom") == 0 || ft_strcmp(flag, "-cre") == 0
		|| ft_strcmp(flag, "-cim") == 0)
		return (is_valid_float(value));
	return (0);
}
