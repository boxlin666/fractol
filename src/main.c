/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:11:44 by helin             #+#    #+#             */
/*   Updated: 2025/07/31 19:13:33 by helin            ###   ########.fr       */
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
	if (!img->mlx)
	{
		ft_putendl_fd("Error: mlx_init failed", 2);
		exit(1);
	}
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Fractal Viewer");
	if (!img->win)
	{
		ft_putendl_fd("Error: mlx_new_window failed", 2);
		exit(1);
	}
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		ft_putendl_fd("Error: mlx_new_image failed", 2);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	img->color_shift = 0;
}

int	render_frame(t_data *img)
{
	if (!img | !img->need_redraw)
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
	img->color_shift += 1;
	return (0);
}

int	close_window(t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	free(img);
	exit(0);
	return (0);
}

t_data	*create_data(int argc, char **argv)
{
	t_data	*img;

	if (argc < 2)
		return (ft_putendl_fd
			("Usage: ./fractol [mandelbrot|julia|tricorn] [options]",
				2), NULL);
	img = malloc(sizeof(t_data));
	if (!img)
		return (ft_putendl_fd("Error: malloc failed", 2), NULL);
	ft_memset(img, 0, sizeof(t_data));
	if (!init_data(img, argc, argv))
	{
		return (free(img), NULL);
	}
	return (img);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	img = create_data(argc, argv);
	if (!img)
		return (1);
	init_mlx(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_hook(img->win, 2, 1L << 0, key_hook, img);
	mlx_hook(img->win, 17, 0, close_window, img);
	mlx_hook(img->win, 4, 1L << 2, mouse_press, img);
	mlx_hook(img->win, 5, 1L << 3, mouse_release, img);
	mlx_hook(img->win, 6, 1L << 6, mouse_move, img);
	mlx_loop_hook(img->mlx, render_frame, img);
	mlx_loop(img->mlx);
	return (0);
}
