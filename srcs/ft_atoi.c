/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:41:37 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 10:41:37 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	check_overflow(long num, const char *nptr, int sign)
{
	if (sign == 1)
	{
		if ((num == (LONG_MAX / 10) && (*nptr - '0') > 7)
			|| num >= (LONG_MAX / 10) + 1)
			return (-1);
	}
	if (sign == -1)
	{
		if ((num == (LONG_MAX / 10) && (*nptr - '0') > 8)
			|| num >= (LONG_MAX / 10) + 1)
			return (0);
	}
	return (1);
}

static	long	ft_strtol(const char *nptr)
{
	long	num;
	int		sign;
	int		flag;

	num = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		flag = check_overflow(num, nptr, sign);
		if (flag == -1)
			return (LONG_MAX);
		else if (flag == 0)
			return (LONG_MIN);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

int	ft_atoi(const char *nptr)
{
	return ((int)ft_strtol(nptr));
}
