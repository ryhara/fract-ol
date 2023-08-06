/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:36:39 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/06 09:36:55 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in_mandelbrot(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->size = data->size * 0.9;
	mandelbrot_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_out_mandelbrot(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->size = data->size * 1.1;
	mandelbrot_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_in_julia(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->size = data->size * 0.9;
	data->base_coler = data->base_coler * 2;
	if (data->base_coler < 1)
		data->base_coler = 0x00FFFF;
	julia_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_out_julia(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->size = data->size * 1.1;
	data->base_coler = data->base_coler * 2;
	if (data->base_coler < 1)
		data->base_coler = 0x00FFFF;
	julia_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
