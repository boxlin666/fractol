/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:28:33 by helin             #+#    #+#             */
/*   Updated: 2025/05/06 14:37:57 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTACTOL_H
# define FTACTOL_H
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

void		render_mandelbrot(t_data *img);
double		scale(double value, double min_screen, double max_screen,
				double min_complex, double max_complex);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif