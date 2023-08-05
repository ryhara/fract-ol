/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:19:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 19:02:06 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp("mandelbrot", argv[1]))
			mandelbrot();
		else
			return (ft_putexample());
	}
	else if (argc == 4)
	{
		if (ft_strcmp("julia", argv[1]))
			return (ft_putexample());
		if (!check_args(argc, argv))
			return (ft_putexample());
		if (!ft_strcmp("julia", argv[1]))
			julia(ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
		return (ft_putexample());
}

// test case
// ./fractol julia 0.32 0.043
// ./fractol julia 0.27334 0.00742
// ./fractol julia -0.15652 1.03225
// ./fractol julia -0.12 0.74
// ./fractol julia -0.39054 -0.58679
// ./fractol julia 0.11031 -0.67037
// ./fractol julia 0.11031 -0.67037
// ./fractol julia -0.74543 0.11301