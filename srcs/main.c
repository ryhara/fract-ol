/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:19:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 18:13:08 by ryhara           ###   ########.fr       */
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
			return (ft_puterr("Input two float numbers from -2 to 2\n"));
		if (!ft_strcmp("julia", argv[1]))
			julia(ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
		return (ft_putexample());
}
