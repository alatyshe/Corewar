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

int					live_func(t_functions *func, int line, char *str)
{
	int				i;
	int				j;

	i = skip_spaces_before_after_cmd(str);
	func->func_id = 1;
	if (str[i] == '\0')
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", i + 1, line);
		return (0);
	}
	else if (str[i] == ';')
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", i + 1, line);
		return (0);		
	}
	else if (ft_isdigit(str[i]) || str[i] != '%')
	{
		ft_printf("Invalid parameter 0 type register for instruction live\n");
		return (0);
	}
	else if (str[i] == '%')
	{
		i++;
		if (str[i] == '\0')
		{
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", i, line);
			return (0);
		}
		func->arg_1.num = ft_atoi(str + i);
		j = skip_numbers(str + i + 1);
		if (ft_isblank(str[i + 1]))
		{
			j = skip_spaces(str + i);
			if (str[i + j] != ';')
			{
				ft_printf("Lexical error at [%d:%d]\n", i - 1, line);
				return (0);
			}
		}
		else if (ft_isalnum(str[i + 1]) && !ft_isdigit(str[i + 1]))
		{
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", i - j - 1, line, str + i + 1);
			return (0);
		}
		ft_printf("%sARG_1 : %ld%s\n", MAGENTA, func->arg_1.num, RESET);
	}
	ft_printf("%02X\n", func->func_id);
	return (1);
}