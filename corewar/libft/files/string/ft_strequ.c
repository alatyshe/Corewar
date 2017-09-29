/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:04:16 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/13 17:14:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned long int	i;
	char				*str1;
	char				*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 && s2)
	{
		while (str1[i] || str2[i])
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
