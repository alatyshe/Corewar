/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:02:39 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/13 20:24:29 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

intmax_t			ft_atoi(const char *str)
{
	unsigned long	i;
	intmax_t		b;
	int				z;

	i = 0;
	b = 0;
	z = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
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
	return (b * z);
}
