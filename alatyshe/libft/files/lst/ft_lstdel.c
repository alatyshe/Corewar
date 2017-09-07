/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:17:14 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/08 20:05:12 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *res;
	t_list *temp;

	res = *alst;
	while (res)
	{
		temp = res;
		res = res->next;
		del(temp->content, temp->content_size);
		free(temp);
	}
	*alst = NULL;
}
