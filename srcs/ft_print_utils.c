/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:19:22 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 19:10:41 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_puterr(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	return (1);
}

int	ft_putexample(void)
{
	ft_puterr("Available fractal sets:\n");
	ft_puterr("・mandelbrot (e.g.) $ ./fractol mandelbrot\n");
	ft_puterr("・julia      (e.g.) $ ./fractol julia float_a float_b ");
	ft_puterr("(float numbers from -2 to 2)\n");
	return (1);
}
