/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:28:33 by helin             #+#    #+#             */
/*   Updated: 2025/07/25 13:16:16 by helin            ###   ########.fr       */
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
# define DEFAULT_CR -0.8
# define DEFAULT_CI 0.156

/* 
./fractol julia -cre 0.355 -cim 0.355 -iter 3000
./fractol julia -cre -0.7 -cim 0.27015 -iter 3000
./fractol julia -cre 0.285 -cim 0
*/
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
	int		color_shift;
	double	c_re;
	double	c_im;
}			t_data;

typedef struct s_range
{
	double	min;
	double	max;
}			t_range;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

int			init_data(t_data *img, int argc, char **argv);
int			key_hook(int keycode, t_data *img);
int			mouse_hook(int button, int x, int y, t_data *img);
int			mouse_press(int button, int x, int y, t_data *img);
int			mouse_release(int button, int x, int y, t_data *img);
int			mouse_move(int x, int y, t_data *img);

int			render_frame(t_data *img);
void		render_mandelbrot(t_data *img);
void		render_julia(t_data *img);
void		render_tricorn(t_data *img);

double		map(int value, t_range src, t_range dst);
double		scale(double value, t_range screen, t_range complex);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_color(int iter, int max_iter);
t_rgb		hsv_to_rgb(double h, double s, double v);
int			get_shifted_color(int iter, int max_iter, int shift);
int			get_smooth_color(int iter, int max_iter);
double		ft_atof(const char *str);
#endif