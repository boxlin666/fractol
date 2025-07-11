/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:28:33 by helin             #+#    #+#             */
/*   Updated: 2025/07/11 22:34:42 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
# define KEY_ESC 65307
# define ZOOM_FACTOR 1.1
# define FRACTAL_MANDELBROT 1
# define FRACTAL_JULIA 2
# define FRACTAL_TRICORN 3

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		is_dragging;
	int		last_x;
	int		last_y;
	int		need_redraw;
	int		fractal_type;
}			t_data;

int			init_data(t_data *img, int argc, char **argv);
int			key_hook(int keycode, t_data *img);
int			mouse_hook(int button, int x, int y, t_data *img);
int			mouse_press(int button, int x, int y, t_data *img);
int			mouse_release(int button, int x, int y, t_data *img);
int			mouse_move(int x, int y, t_data *img);

void		render_mandelbrot(t_data *img);
void		render_julia(t_data *img);
void		render_tricorn(t_data *img);

double		scale(double value, double min_screen, double max_screen,
				double min_complex, double max_complex);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_color(int iter, int max_iter);
int			get_psychedelic_color(int iter, int max_iter);
int			get_shifted_color(int iter, int max_iter, int shift);
int			get_smooth_color(int iter, int max_iter);

#endif