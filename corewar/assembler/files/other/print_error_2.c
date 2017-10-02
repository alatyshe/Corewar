/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					error_type(t_header *head, int type, int error)
{
	head->error = error;
	if (type == SYNTAX_ERROR)
		ft_putstr_fd("Syntax error at token [TOKKEN]", 2);
	if (type == LEXICAL_ERROR)
		ft_putstr_fd("Lexical error at ", 2);
	if (type == INVALID_INSTR)
		ft_putstr_fd("Invalid instruction at token [TOKKEN]", 2);
	if (type == INVALID_PAR)
		ft_putstr_fd("Invalid parameter ", 2);
	if (type == NO_LABEL)
	{
		ft_putstr_fd("No such label while attempting ", 2);
		ft_putstr_fd("to dereference token [TOKKEN]", 2);
	}
	return (0);
}

void				error_invalid_argument(t_header *head, t_cmd *cmd,
	char *read, int arg_num)
{
	head->error = EMPTY;
	if (read[0] == DIRECT_CHAR)
		error_arg(cmd, INVALID_PAR, arg_num, "direct");
	else if (read[0] == REGISTER_CHAR)
		error_arg(cmd, INVALID_PAR, arg_num, "register");
	else if (ft_isdigit(read[0]))
		error_arg(cmd, INVALID_PAR, arg_num, "indirect");
	else
		error_type(head, SYNTAX_ERROR, LBL_INSTR);
}

int					error_arg(t_cmd *cmd, int type,
	int argc, char *type_arg)
{
	if (type == INVALID_PAR)
	{
		ft_putstr_fd("Invalid parameter ", 2);
		ft_putnbr_fd(argc, 2);
		ft_putstr_fd(" type ", 2);
		ft_putstr_fd(type_arg, 2);
		ft_putstr_fd(" for instruction ", 2);
		ft_putstr_fd(g_tab[cmd->code - 1].name, 2);
		ft_putstr_fd(" [TOKKEN]", 2);
	}
	if (type == PROG_NAME_LENGTH)
		ft_putstr_fd("Champion name too long (Max length 128)\n", 2);
	if (type == COMMENT_LENGTH)
		ft_putstr_fd("Champion comment too long (Max length 2048)\n", 2);
	return (0);
}
