/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:31:06 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/06 09:46:10 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_space_sign(int i, char **argv)
{
	int	j;

	j = 0;
	while ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
		j++;
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	return (j);
}

static BOOLEAN	check_number(char *s, int j)
{
	double	num;

	num = 0;
	while (s[j] >= '0' && s[j] <= '9')
	{
		num = num * 10 + (s[j++] - '0');
		if (num > 2 || num * -1 < -2)
			return (FALSE);
		if (s[j] == '.')
		{
			j++;
			if (num == 2)
			{
				while (s[j] == '0')
					j++;
				break ;
			}
			while (s[j] >= '0' && s[j] <= '9')
				j++;
			break ;
		}
	}
	if (s[j] != '\0')
		return (FALSE);
	return (TRUE);
}

BOOLEAN	check_args(int argc, char **argv)
{
	int		i;
	int		j;

	i = 2;
	while (i < argc)
	{
		j = check_space_sign(i, argv);
		if (argv[i][j] == '\0')
			return (FALSE);
		if (!check_number(argv[i], j))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
