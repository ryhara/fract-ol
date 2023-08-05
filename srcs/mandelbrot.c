/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:27:06 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 18:41:16 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_set(t_data *data, int i, int j, float size)
{
	data->a = i * size / WIDTH - size / 2;
	data->b = j * size / HEIGHT - size / 2;
	data->x = 0;
	data->y = 0;
}

static void	mandelbrot_calc(t_data *data)
{
	float	x_tmp;
	float	y_tmp;

	x_tmp = data->x * data->x - data->y * data->y + data->a;
	y_tmp = 2 * data->x * data->y + data->b;
	data->x = x_tmp;
	data->y = y_tmp;
}

static void	mandelbrot_put(t_data *data, int i, int j)
{
	int	k;

	k = 0;
	mandelbrot_set(data, i, j, data->size);
	while (k < CALC_COUNT)
	{
		mandelbrot_calc(data);
		if (data->x * data->x + data->y * data->y > 4)
		{
			my_mlx_pixel_put(data, i, j, data->base_coler / (k + 1));
			break ;
		}
		k++;
	}
}

void	mandelbrot_drow(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mandelbrot_put(data, i, j);
			j++;
		}
		i++;
	}
}

void	mandelbrot(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.size = 4;
	data.base_coler = 0x00FFFF00;
	mandelbrot_drow(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, ON_KEYDOWN, 0, close_esc, &data);
	mlx_hook(data.win, ON_MOUSEDOWN, 0, mouse_hook_mandel, &data);
	mlx_hook(data.win, ON_DESTROY, 0, close_x, &data);
	mlx_loop(data.mlx);
}
