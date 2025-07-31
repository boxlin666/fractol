/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:21:39 by helin             #+#    #+#             */
/*   Updated: 2025/07/31 19:23:59 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static int	parse_args(t_data *img, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-zoom") == 0 || ft_strcmp(argv[i], "-cre") == 0
				|| ft_strcmp(argv[i], "-cim") == 0) && i + 1 < argc)
		{
			if (!validate_param(argv[i], argv[i + 1]))
				return (ft_putendl_fd("Error: Invalid argument value", 2), 0);
		}
		if (ft_strcmp(argv[i], "-zoom") == 0 && i + 1 < argc)
			img->zoom = ft_atof(argv[++i]);
		else if (ft_strcmp(argv[i], "-cre") == 0 && i + 1 < argc)
			img->c_re = ft_atof(argv[++i]);
		else if (ft_strcmp(argv[i], "-cim") == 0 && i + 1 < argc)
			img->c_im = ft_atof(argv[++i]);
		else
			return (ft_putendl_fd("Error: Invalid arguments", 2), 0);
		i++;
	}
	return (1);
}

int	init_data(t_data *img, int argc, char **argv)
{
	img->zoom = 1.0;
	img->offset_x = 0.0;
	img->offset_y = 0.0;
	img->max_iter = MAX_ITER;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		img->fractal_type = FRACTAL_MANDELBROT;
		img->offset_x = -0.4;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
		img->fractal_type = FRACTAL_JULIA;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		img->fractal_type = FRACTAL_TRICORN;
	else
		return (ft_putendl_fd("Error: Unknown fractal type", 2), 0);
	img->is_dragging = 0;
	img->last_x = 0;
	img->last_y = 0;
	img->need_redraw = 1;
	img->c_re = DEFAULT_CR;
	img->c_im = DEFAULT_CI;
	return (parse_args(img, argc, argv));
}
