/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:18:56 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/16 15:28:08 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

int		ft_search_h(char *str, int *i)
{
	int		j;

	j = (*i) + 1;
	while (str[j])
	{
		if (str[j] == 'h')
			return (j - (*i));
		if (str[j] != ' ')
			break ;
		j++;
	}
	return (0);
}

int		ft_check_length(t_pflist *lst, char *str, int *i)
{
	if (str[(*i)] == 'h' && ft_search_h(str, i))
	{
		(*i) += ft_search_h(str, i);
		lst->length = 1;
	}
	else if (str[(*i)] == 'h')
		lst->length < 2 ? lst->length = 2 : lst->length;
	else if (str[(*i)] == 'l')
		lst->length < 3 ? lst->length = 3 : lst->length;
	else if (str[(*i)] == 'l' && str[(*i) + 1] == 'l')
	{
		(*i)++;
		lst->length < 4 ? lst->length = 4 : lst->length;
	}
	else if (str[(*i)] == 'j')
		lst->length < 5 ? lst->length = 5 : lst->length;
	else if (str[(*i)] == 'z')
		lst->length < 6 ? lst->length = 6 : lst->length;
	else if (str[(*i)] == ' ')
		lst->spc = 1;
	else
		return (0);
	return (1);
}

void	ft_func_star(t_pflist *lst, char *str, int *i, va_list ap)
{
	int		a;

	if (str[(*i)] == '*' && lst->dot == 0)
	{
		a = va_arg(ap, int);
		if (a < 0)
		{
			lst->minus = 1;
			a = -a;
		}
		lst->width = a;
	}
	else if (str[(*i)] == '*' && lst->dot == 1)
	{
		a = va_arg(ap, intmax_t);
		if (a >= 0)
		{
			lst->dot = 1;
			lst->prec = a;
		}
		else
			lst->dot = 0;
	}
}

int		ft_lst_fill(t_pflist *lst, char *str, int *i, va_list ap)
{
	if (str[(*i)] == '#')
		lst->hash = 1;
	else if (str[(*i)] == '+')
		lst->plus = 1;
	else if (str[(*i) - 1] == '.' && ft_check_for_atoi(&str[(*i)]))
		lst->prec = ft_atoi_plus(&str[(*i)], i);
	else if (str[(*i)] == '0')
		lst->zero = (lst->minus == 0) ? 1 : 0;
	else if (str[(*i)] == '-')
		lst->minus = 1;
	else if (str[(*i)] == '.')
	{
		lst->prec = 0;
		lst->dot = 1;
	}
	else if (str[(*i)] != '0' && ft_check_for_atoi(&str[(*i)]))
	{
		lst->width = ft_atoi_plus(&str[(*i)], i);
		lst->prec = (str[(*i) + 1] == '.') ? 0 : lst->prec;
	}
	else if (str[(*i)] == '*')
		ft_func_star(lst, str, i, ap);
	else
		return (ft_check_length(lst, str, i));
	return (1);
}
