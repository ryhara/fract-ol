/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:19:22 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 19:01:57 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n <= -10)
			ft_putnbr_fd((n / -10), fd);
		n = n % 10 * -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
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
