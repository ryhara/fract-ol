/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:03:52 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/03 20:01:27 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(float a, float b)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	vars.a = a;
	vars.b = b;
	julia_drow(&vars);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYDOWN, 0, close_esc, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_x, &vars);
	mlx_loop(vars.mlx);
}

void julia_calc(t_vars *vars)
{
	double x_tmp;
	double y_tmp;

	x_tmp = vars->x * vars->x - vars->y * vars->y + vars->a;
	y_tmp = 2 * vars->x * vars->y + vars->b;
	vars->x = x_tmp;
	vars->y = y_tmp;
}

void julia_drow(t_vars *vars)
{
	int	i;
	int	j;
	int	k;
	double size;

	i = 0;
	size = 1;
	while (i < WIDTH)
	{
		// vars->a = i * size / WIDTH - size / 2;
		vars->a = 0;
		j = 0;
		while (j < HEIGHT)
		{
			// vars->b = j * size / HEIGHT  - size / 2;
			vars->b = 0;
			vars->x = 0;
			vars->y = 0;
			k = 0;
			while (k < 50)
			{
				julia_calc(vars);
				if (vars->x * vars->x + vars->y * vars->y > 4)
				{
					my_mlx_pixel_put(&vars->img, i, j, 0x00FF0000);
					break;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
