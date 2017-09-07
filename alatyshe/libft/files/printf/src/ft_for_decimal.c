/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:58:27 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/08 13:11:05 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

int		ft_check_for_atoi(char *str)
{
	int				i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi_plus(const char *str, int *c)
{
	unsigned long	i;
	int				b;
	int				z;

	i = 0;
	b = 0;
	z = 1;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		i++;
		z = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = b * 10 + (str[i] - 48);
		i++;
	}
	(*c) = (*c) + i - 1;
	return (b * z);
}
