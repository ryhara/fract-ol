/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:31:06 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/03 19:57:35 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

BOOLEAN check_args(char **argv)
{
	float	a;
	float	b;

	a = ft_atof(argv[2]);
	b = ft_atof(argv[3]);
	if (a < -2 || a > 2 || b < -2 || b > 2)
		return (FALSE);
	else
		return (TRUE);
}