/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:04:14 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:04:15 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_c(t_pflist *lst, int *count, va_list ap)
{
	char	c;

	if (lst->length == 3)
		ft_c_big(lst, count, ap);
	else
	{
		c = (char)va_arg(ap, int);
		if (lst->minus == 0 && lst->width > 0 && lst->minus == 0)
		{
			if (lst->zero == 0)
				*count += ft_char(lst->width - 1, ' ');
			else
				*count += ft_char(lst->width - 1, '0');
			*count += ft_char(1, c);
		}
		else if (lst->width > 0 && lst->minus == 1)
		{
			*count += ft_char(1, c);
			*count += ft_char(lst->width - 1, ' ');
		}
		else
			*count += ft_char(1, c);
	}
}
