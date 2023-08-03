/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:19:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/03 17:24:25 by ryhara           ###   ########.fr       */
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
			julia();
	}
	else if (argc == 4)
	{
		;
	}
	else
		return (0);

}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fractol");
}