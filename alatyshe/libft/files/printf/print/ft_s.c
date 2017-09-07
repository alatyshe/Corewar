/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:11 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:12 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_print_s2(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str);
	*count += ft_prnstr(str, lst->prec);
	if (lst->zero == 0 && *str && lst->prec > 0 &&
		len > lst->prec && lst->width > lst->prec)
		*count += (ft_char(lst->width - lst->prec, ' '));
	else if (lst->zero == 0 && *str &&
		(len < lst->prec || lst->dot == 0) && lst->width > len)
		*count += (ft_char(lst->width - len, ' '));
	else if (lst->zero == 0 && *str && lst->dot == 1 && lst->prec == 0)
		*count += (ft_char(lst->width, ' '));
	else if (lst->zero == 0 && !*str)
		*count += (ft_char(lst->width, ' '));
	else if (lst->zero == 1 && lst->width > len)
		*count += (ft_char(lst->width - len, '0'));
}

void	ft_print_s(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (lst->minus == 0 && lst->width > 0)
	{
		if (lst->zero == 0)
			*count += (ft_char(lst->width - lst->prec, ' '));
		else if (lst->zero == 1 && lst->prec <= len)
			*count += (ft_char(lst->width - lst->prec, '0'));
		else if (lst->zero == 1 && lst->prec >= len)
			*count += (ft_char(lst->width - len, '0'));
		if (lst->zero == 0 && lst->prec > len)
			*count += (ft_char(lst->prec - len, ' '));
		if (*str && ((lst->dot == 1 && lst->prec > 0) || lst->dot == 0))
			*count += ft_prnstr(str, lst->prec);
	}
	else if (lst->minus == 1 && lst->width > 0)
		ft_print_s2(lst, count, str);
	else
	{
		if (lst->dot == 0)
			*count += ft_prnstr(str, lst->prec);
		else if (lst->dot > 0 && lst->prec > 0)
			*count += ft_prnstr(str, lst->prec);
	}
}

void	ft_s(t_pflist *lst, int *count, va_list ap)
{
	char	*str;

	if (lst->length == 3)
		ft_s_big(lst, count, ap);
	else
	{
		str = (char *)va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_lst_modify_s(lst, str);
		ft_print_s(lst, count, str);
	}
}
