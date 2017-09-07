/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:34:25 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/13 17:31:33 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = (void *)malloc(sizeof(res) * size + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
