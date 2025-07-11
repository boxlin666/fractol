/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:11:44 by helin             #+#    #+#             */
/*   Updated: 2025/07/11 22:39:54 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	init_mlx(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Fractal Viewer");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
}

int	render_frame(t_data *img)
{
	if (!img->need_redraw)
	{
		return (0);
	}
	if (img->fractal_type == FRACTAL_MANDELBROT)
		render_mandelbrot(img);
	else if (img->fractal_type == FRACTAL_JULIA)
		render_julia(img);
	else if (img->fractal_type == FRACTAL_TRICORN)
		render_tricorn(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	img->need_redraw = 0;
	return (0);
}

int	close_window(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data img;

	if (argc < 2)
	{
		ft_putendl_fd("Usage: ./fractol [mandelbrot|julia|tricorn] [options]",
			2);
		return (1);
	}
	if (!init_data(&img, argc, argv))
		return (1);
	init_mlx(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_hook(img.win, 4, 1L << 2, mouse_press, &img);
	mlx_hook(img.win, 5, 1L << 3, mouse_release, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse_move, &img);
	mlx_loop_hook(img.mlx, render_frame, &img);
	mlx_loop(img.mlx);
	return (0);
}
