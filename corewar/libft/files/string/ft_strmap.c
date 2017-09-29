/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:45:49 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/04 18:59:24 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*b;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	b = (char*)malloc(sizeof(char) * i + 1);
	if (!b)
		return (NULL);
	i = 0;
	while (s[i])
	{
		b[i] = (*f)(s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
