/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void			error_line_char_types_2(t_header *head,
	char *str, int start)
{
	if (head->error == LBL_INSTR)
	{
		if (find_chars_in_str(str, ":") < 0)
			ft_putstr_fd("INSTRUCTION ", 2);
		else
			ft_putstr_fd("LABEL ", 2);
	}
	else if (head->error == DIRECT)
		ft_putstr_fd("DIRECT ", 2);
	else if (head->error == DIRECT_LABEL)
		ft_putstr_fd("DIRECT_LABEL ", 2);
	else if (head->error == INSTRUCTION)
		ft_putstr_fd("INSTRUCTION ", 2);
	else if (head->error == REGISTER)
		ft_putstr_fd("REGISTER ", 2);
	else if (head->error == INDIRECT)
		ft_putstr_fd("INDIRECT ", 2);
	ft_putstr_fd(str + start, 2);
	ft_putchar_fd('\"', 2);
}

static int			error_line_char_types_1(t_header *head)
{
	if (head->error == END)
		ft_putstr_fd("END \"(null)\"", 2);
	else if (head->error == STRING_AFTER)
		ft_putstr_fd("STRING AFTER \"\"\"", 2);
	else if (head->error == ENDLINE)
		ft_putstr_fd("ENDLINE", 2);
	else if (head->error == COMMAND_NAME)
		ft_putstr_fd("COMMAND_NAME \".name\"", 2);
	else if (head->error == COMMAND_COMMENT)
		ft_putstr_fd("COMMAND_COMMENT \".comment\"", 2);
	else
		return (0);
	return (1);
}

int					error_line_char(t_header *head, char *str)
{
	int				end;
	int				start;

	start = skip_spaces(str);
	if (str != NULL)
	{
		end = find_chars_in_str(str + start, "\n\t\r\f\v ,\"");
		if (end != -1)
			str[end + start] = '\0';
	}
	ft_putchar_fd('[', 2);
	ft_putnbr_fd(head->line, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(head->x + 1, 2);
	ft_putchar_fd(']', 2);
	if (!error_line_char_types_1(head))
		error_line_char_types_2(head, str, start);
	ft_putchar_fd('\n', 2);
	return (0);
}
