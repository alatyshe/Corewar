/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:04:29 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:04:30 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_percent(t_pflist *lst, int *count)
{
	if (lst->width > 0 && lst->minus == 0)
	{
		if (lst->zero == 0)
			*count += ft_char(lst->width - 1, ' ');
		else
			*count += ft_char(lst->width - 1, '0');
		*count += ft_char(1, '%');
	}
	else if (lst->width > 0 && lst->minus == 1)
	{
		*count += ft_char(1, '%');
		*count += ft_char(lst->width - 1, ' ');
	}
	else
		*count += ft_char(1, '%');
}
