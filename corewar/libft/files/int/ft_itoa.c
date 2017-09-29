/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:26:59 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/08 16:13:20 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int					num_count(int n)
{
	size_t			i;
	long int		b;

	i = 0;
	b = (long int)n;
	if (b < 0)
	{
		b *= -1;
		i++;
	}
	while (b >= 10)
	{
		i++;
		b = b / 10;
	}
	if (b < 10 && b >= 0)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	unsigned int	i;
	char			*b;
	long int		s;
	int				c;

	c = 1;
	s = (size_t)n;
	i = num_count(n);
	b = (char *)malloc(sizeof(char) * num_count(n) + 1);
	if (!b)
		return (NULL);
	b[i] = '\0';
	if (s < 0)
	{
		s *= -1;
		c = -1;
	}
	while (i--)
	{
		b[i] = s % 10 + 48;
		s = s / 10;
	}
	if (c == -1)
		b[0] = '-';
	return (b);
}
