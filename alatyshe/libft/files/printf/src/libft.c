/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:27:57 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/05 19:23:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

int		ft_size_bin(wchar_t a)
{
	int		j;

	j = 0;
	while (a >= 2)
	{
		a = a / 2;
		j++;
	}
	j++;
	return (j);
}

size_t	ft_strlen_big(wchar_t *s)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = ft_size_bin(s[i]);
		if (j <= 7)
			k += 1;
		else if (j <= 11)
			k += 2;
		else if (j <= 16)
			k += 3;
		else
			k += 4;
		i++;
	}
	return (k);
}
