/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/other.h"

int					error_message_type(int type, t_header *head, int x, int error)
{
	head->error = error;
	if (type == 1)
		ft_putstr_fd("Syntax error at token [TOKKEN]", 2);
	if (type == 2 && (head->error = 2))
		ft_putstr_fd("Lexical error at ", 2);
	if (type == 3)
		ft_putstr_fd("Invalid instruction at token [TOKKEN]", 2);
	if (type == 4)
		ft_putstr_fd("Invalid parameter ", 2);
	return (x + 1);
}

void 				*error_message_y_x(t_header *head, int y, int x, char *str)
{
	ft_printf("[%03d:%03d] ", y, x);

	if (head->error == 1)
	{
		if (find_chars_in_str(str, ":") < 0)
			ft_printf("INSTRUCTION \"%s\"", str);
		else
			ft_printf("LABEL \"%s\"", str);
	}
	else if (head->error == 2)
		ft_printf("END \"(null)\"", str);
	else if (head->error == 3)	
		ft_printf("STRING AFTER \"%s\"", str);
	ft_putchar_fd('\n', 2);
	return (NULL);
}