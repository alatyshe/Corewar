/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int			skip_spaces_before_after_cmd(char *str)
{
	int				i;

	i = 0;
	if (ft_isblank(str[i]))
		while (ft_isblank(str[i]))
			i++;
	if (ft_isalpha(str[i]))
		while (ft_isalpha(str[i]))
			i++;
	if (ft_isblank(str[i]))
		while (ft_isblank(str[i]))
			i++;
	return (i);
}

static int			skip_numbers(char *str)
{
	int			i;

	i = 0;

	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}


int					live_func(t_functions *func, int line, char *str)
{
	int				i;

	i = skip_spaces_before_after_cmd(str);
	printf("%s|%s|%s\n", GREEN, str + i, RESET);
	if (str[i] == '\0')
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d]\n", line, i + 1);
		return (0);
	}
	else if (ft_isdigit(str[i]) || str[i] == 'r')
	{
		ft_printf("Invalid parameter 0 type register for instruction live\n");
		return (0);
	}
	else if (str[i] == '%')
	{
		func->arg_1.num = ft_atoi(str + i + 1);
		i += skip_numbers(str + i + 1);
		if (str[i + 1])
		{
			ft_printf("Invalid parameter 0 type register for instruction live\n");
			return (0);
		}
		printf("%sARG_1 : %ld%s\n", MAGENTA, func->arg_1.num, RESET);
	}
	return (1);
}