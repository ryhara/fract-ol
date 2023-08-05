/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:23:55 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 18:32:57 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define BOOLEAN int
# define TRUE 1
# define FALSE 0
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC_KEY 53
# define WIDTH 1000
# define HEIGHT 1000

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# include "../mlx/mlx.h"

typedef struct s_data{
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	float	x;
	float	y;
	float	a;
	float	b;
	float	size;
	int		base_coler;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_esc(int keycode, t_data *data);
int		close_x(t_data *data);
int		mouse_hook_mandel(int button, int x, int y, t_data *data);
int		mouse_hook_julia(int button, int x, int y, t_data *data);

void	mandelbrot(void);
void	mandelbrot_drow(t_data *data);

void	julia(float a, float b);
void	julia_drow(t_data *data);

void	color_change_mandelbrot(t_data *data, int button);
void	color_change_julia(t_data *data, int button);
void	zoom_in_mandelbrot(t_data *data);
void	zoom_out_mandelbrot(t_data *data);
void	zoom_in_julia(t_data *data);
void	zoom_out_julia(t_data *data);

BOOLEAN	check_args(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);
double	ft_atof(const char *string);
void	ft_putstr_fd(char *s, int fd);
int		ft_puterr(char *s);
int		ft_putexample(void);

#endif