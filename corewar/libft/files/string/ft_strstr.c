/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:35:44 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/01 14:44:38 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	if (!(*little))
		return ((char*)big);
	return (0);
}
