/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:12:00 by helin             #+#    #+#             */
/*   Updated: 2025/07/11 22:36:52 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	else if (keycode == 65362)
		img->offset_y -= 0.1 / img->zoom;
	else if (keycode == 65364)
		img->offset_y += 0.1 / img->zoom;
	else if (keycode == 65361)
		img->offset_x -= 0.1 / img->zoom;
	else if (keycode == 65363)
		img->offset_x += 0.1 / img->zoom;
	else if (keycode == 65451)
		img->zoom *= 1.2;
	else if (keycode == 65453)
		img->zoom /= 1.2;
	render_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom_factor = 1.2;
		else
			zoom_factor = 1 / 1.2;
		mouse_re = (x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH)
			+ img->offset_x;
		mouse_im = (y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT)
			+ img->offset_y;
		img->zoom *= zoom_factor;
		img->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * img->zoom
				* WIDTH);
		img->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * img->zoom
				* HEIGHT);
		render_mandelbrot(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *img)
{
	double	mouse_re;
	double	mouse_im;

	if (button == 1)
	{
		img->is_dragging = 1;
		img->last_x = x;
		img->last_y = y;
	}
	else if (button == 4 || button == 5)
	{
		mouse_re = (double)x / WIDTH * 3.0 - 2.0;
		mouse_im = (double)y / HEIGHT * 3.0 - 1.5;
		mouse_re = mouse_re / img->zoom + img->offset_x;
		mouse_im = mouse_im / img->zoom + img->offset_y;
		if (button == 4)
			img->zoom *= ZOOM_FACTOR;
		else if (button == 5)
			img->zoom /= ZOOM_FACTOR;
		img->offset_x = mouse_re - ((double)x / WIDTH * 3.0 - 2.0) / img->zoom;
		img->offset_y = mouse_im - ((double)y / HEIGHT * 3.0 - 1.5) / img->zoom;
		img->need_redraw = 1;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *img)
{
	(void)(x + y);
	if (button == 1)
	{
		img->is_dragging = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *img)
{
	int	dx;
	int	dy;

	if (!img->is_dragging)
		return (0);
	dx = x - img->last_x;
	dy = y - img->last_y;
	img->offset_x -= (double)dx / (0.5 * img->zoom * WIDTH);
	img->offset_y -= (double)dy / (0.5 * img->zoom * HEIGHT);
	img->last_x = x;
	img->last_y = y;
	img->need_redraw = 1;
	return (0);
}
