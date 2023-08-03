/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:19:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/03 20:17:15 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char **argv)
{
	if (argc == 1)
		mandelbrot();
	else if (argc == 2)
	{
		if (!ft_strcmp("mandelbrot", argv[1]))
			mandelbrot();
		else if (!ft_strcmp("julia", argv[1]))
			julia(0, 0);
	}
	else if (argc == 4)
	{
		printf("%f %f\n", ft_atof(argv[2]), ft_atof(argv[3]));
		if (!ft_strcmp("julia", argv[1]))
			return (1);
		if (!check_args(argv))
		{
			printf("error\n\n");
			return (1);
		}
		else
			julia(0, 0);
	}
	else
		return (1);

}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fractol");
}