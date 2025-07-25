/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:21:39 by helin             #+#    #+#             */
/*   Updated: 2025/07/14 16:10:31 by helin            ###   ########.fr       */
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
		if (ft_strncmp(argv[i], "-zoom", 5) == 0 && i + 1 < argc)
			img->zoom = ft_atof(argv[++i]);
		else if (ft_strncmp(argv[i], "-iter", 5) == 0 && i + 1 < argc)
			img->max_iter = ft_atoi(argv[++i]);
		else if (ft_strncmp(argv[i], "-cre", 5) == 0 && i + 1 < argc)
			img->c_re = ft_atof(argv[++i]);
		else if (ft_strncmp(argv[i], "-cim", 5) == 0 && i + 1 < argc)
			img->c_im = ft_atof(argv[++i]);
		else
		{
			ft_putendl_fd("Error: Invalid arguments", 2);
			return (0);
		}
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
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		img->fractal_type = FRACTAL_MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		img->fractal_type = FRACTAL_JULIA;
	else if (ft_strncmp(argv[1], "tricorn", 7) == 0)
		img->fractal_type = FRACTAL_TRICORN;
	else
	{
		ft_putendl_fd("Error: Unknown fractal type", 2);
		return (0);
	}
	img->max_iter = 100;
	img->is_dragging = 0;
	img->last_x = 0;
	img->last_y = 0;
	img->need_redraw = 1;
	img->c_re = DEFAULT_CR;
	img->c_im = DEFAULT_CI;
	return (parse_args(img, argc, argv));
}
