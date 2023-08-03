/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:23:55 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/03 17:49:55 by ryhara           ###   ########.fr       */
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
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define ESC_KEY 53
# define WIDTH 500
# define HEIGHT 500

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# include "../mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;

	t_data img;

	double x;
	double y;
	double a;
	double b;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_esc(int keycode, t_vars *vars);
int		close_x(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	mandelbrot(void);
void	mandelbrot_calc(t_vars *vars);
void	mandelbrot_drow(t_vars *vars);
void	julia(void);
void	julia_calc(t_vars *vars);
void	julia_drow(t_vars *vars);
int		ft_strcmp(const char *s1, const char *s2);


#endif