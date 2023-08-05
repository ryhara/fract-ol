/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:26:31 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 16:51:42 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_esc(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	close_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	mouse_hook_mandel(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == ZOOM_OUT)
		zoom_out_mandelbrot(data);
	else if (button == ZOOM_IN)
		zoom_in_mandelbrot(data);
	else
		color_change_mandelbrot(data, button);
	return (0);
}

int	mouse_hook_julia(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == ZOOM_OUT)
		zoom_out_julia(data);
	else if (button == ZOOM_IN)
		zoom_in_julia(data);
	else
		color_change_julia(data, button);
	return (0);
}
