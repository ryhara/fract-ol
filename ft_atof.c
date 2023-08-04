/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:34:15 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 09:42:37 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *string)
{
	double	sign;
	double	num;
	double	sm_num;

	sign = 1;
	num = 0;
	sm_num = 0;
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		num = num * 10 + (*string - '0');
		string++;
		if (*string == '.')
		{
			string++;
			while (*string >= '0' && *string <= '9')
			{
				sm_num = sm_num * 0.1 + (*string - '0') * 0.1;
				string++;
			}
			break ;
		}
	}
	num = num + sm_num;
	return (num * sign);
}