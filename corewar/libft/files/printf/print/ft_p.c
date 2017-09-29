/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:04:14 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:04:15 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_func_for_zero2(t_pflist *lst, int *count, int flag)
{
	if (lst->prec == 0)
		lst->prec = (flag > 0) ? 1 : 0;
	if (lst->minus == 1)
	{
		*count += ft_prnstr("0x", 0);
		*count += ft_char(lst->prec, '0');
		*count += (lst->width > lst->prec + 2)
			? ft_char(lst->width - lst->prec - 2, ' ') : 0;
	}
	if (lst->minus == 0)
	{
		*count += (lst->width > lst->prec + 2 && lst->zero == 0)
			? ft_char(lst->width - lst->prec - 2, ' ') : 0;
		*count += ft_prnstr("0x", 0);
		*count += (lst->zero == 1) ?
			ft_char(lst->width - lst->prec - 2, '0') : 0;
		*count += ft_char(lst->prec, '0');
	}
}

void	ft_print_p(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0' && lst->minus == 1 && lst->width > 0)
	{
		*count += (lst->hash > 0) ? ft_prnstr("0x", 0) : 0;
		*count += ft_char(lst->prec - len, '0');
		*count += (lst->zero == 0) ? ft_prnstr(str, 0) :
			ft_char(lst->width - len, '0');
		*count += (lst->zero == 0) ? ft_char(lst->width - lst->prec, ' ')
			: ft_prnstr(str, 0);
	}
	else if (str[0] != '0' && lst->minus == 0 && lst->width > 0)
	{
		*count += (lst->zero == 0) ? ft_char(lst->width - lst->prec, ' ') : 0;
		*count += (lst->hash > 0) ? ft_prnstr("0x", 0) : 0;
		*count += ft_char(lst->prec - len, '0');
		*count += (lst->zero > 0) ? ft_char(lst->width - len, '0') : 0;
		*count += ft_prnstr(str, 0);
	}
	else
		ft_func_for_zero2(lst, count, lst->dot ? 0 : 1);
}

void	ft_p(t_pflist *lst, int *count, va_list ap)
{
	int			*d;
	char		*str;
	int			i;

	i = 0;
	d = va_arg(ap, int *);
	str = ft_itoa_base_p((intmax_t)d, 16);
	lst->hash = 1;
	ft_lst_modify_x(lst, str);
	ft_print_p(lst, count, str);
	free(str);
}
