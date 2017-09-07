/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_modify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:27:57 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/05 19:23:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void		ft_lst_modify_x(t_pflist *lst, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0' && lst->hash > 0)
		lst->width -= 2;
	if (str[0] != '0' && lst->prec < len)
		lst->prec = len;
	if (lst->width < lst->prec)
		lst->width = lst->prec;
}

void		ft_lst_modify_b(t_pflist *lst, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0' && lst->prec < len)
		lst->prec = len;
	if (str[0] != '0' && lst->width < lst->prec)
		lst->width = lst->prec;
	if (str[0] == '\0' && lst->dot == 0)
	{
		lst->width += 1;
		lst->prec += 1;
	}
}

void		ft_lst_modify_o(t_pflist *lst, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0')
	{
		if (lst->hash > 0)
		{
			lst->width -= lst->hash;
			lst->prec -= lst->hash;
		}
		if (lst->prec < len)
			lst->prec = len;
		if (lst->width < lst->prec)
			lst->width = lst->prec;
	}
	lst->plus = 0;
}

void		ft_lst_modify_sb(t_pflist *lst, wchar_t *str)
{
	int			len;

	len = ft_strlen_big(str);
	if (lst->width < len && lst->dot != 1)
		lst->width = len;
	if (lst->dot == 1 && lst->width <= lst->prec
		&& lst->prec >= len && lst->width <= len)
	{
		lst->width = len;
		lst->prec = len;
	}
	else if (lst->dot == 1 && lst->width <= lst->prec && lst->width >= len)
		lst->prec = len;
	else if (lst->dot == 1 && lst->width <= lst->prec && lst->prec <= len)
	{
		lst->width = lst->prec;
	}
	if (lst->dot == 0)
		lst->prec = len;
}
