/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:11 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:12 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_print_flags(t_pflist *lst, char *str, int *count, int *i)
{
	int		len;

	len = 1;
	if (lst->minus == 0 && lst->width > 0)
	{
		if (lst->zero == 0 && lst->width > lst->prec)
			*count += (ft_char(lst->width - lst->prec - 1, ' '));
		else if (lst->zero == 1 && lst->width > lst->prec)
			*count += (ft_char(lst->width - lst->prec - 1, '0'));
	}
	else if (lst->minus == 1 && lst->width > 0)
	{
		*count += ft_prnstr(str, 1);
		if (lst->zero == 0 && lst->width > lst->prec)
			*count += (ft_char(lst->width - lst->prec - 1, ' '));
		else if (lst->zero == 1 && lst->width > lst->prec)
			*count += (ft_char(lst->width - lst->prec - 1, '0'));
		(*i)++;
	}
}
