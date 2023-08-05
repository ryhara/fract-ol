/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:28:26 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 18:27:08 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_change_mandelbrot(t_data *data, int button)
{
	if (button == LEFT_CLICK)
		data->base_coler = 0x00FF00FF;
	else if (button == RIGHT_CLICK)
		data->base_coler = 0x00FFFF00;
	else if (button == MIDDLE_CLICK)
		data->base_coler = 0x0000FFFF;
	else
		return ;
	mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mandelbrot_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	color_change_julia(t_data *data, int button)
{
	if (button == LEFT_CLICK)
		data->base_coler = 0x00FF00FF;
	else if (button == RIGHT_CLICK)
		data->base_coler = 0x00FFFF00;
	else if (button == MIDDLE_CLICK)
		data->base_coler = 0x0000FFFF;
	else
		return ;
	mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	julia_drow(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
