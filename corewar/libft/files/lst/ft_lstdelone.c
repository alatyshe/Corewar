/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:26:32 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/08 19:34:40 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del(((*alst)->content), ((*alst)->content_size));
	*alst = NULL;
	free(*alst);
}
