/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

void				error_last_line(t_header *head)
{
	head->error = EMPTY;
	ft_putstr_fd("Syntax error - unexpected end of input", 2);
	ft_putstr_fd("(Perhaps you forgot to end with a newline ?)\n", 2);
}

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
		ft_putstr_fd("No such label while attempting to dereference token [TOKKEN]", 2);
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
		ft_printf("Invalid parameter %d type %s for instruction ", argc, type_arg);
		ft_printf("%s [TOKKEN]", g_tab[cmd->code - 1].name);
	}
	if (type == PROG_NAME_LENGTH)
		ft_printf("Champion name too long (Max length 128)\n");
	if (type == COMMENT_LENGTH)
		ft_printf("Champion comment too long (Max length 2048)\n");
	return (0);
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
	ft_printf("[%03d:%03d] ", head->line, head->x + 1);
	if (head->error == LBL_INSTR)
	{
		if (find_chars_in_str(str, ":") < 0)
			ft_printf("INSTRUCTION \"%s\"", str + start);
		else
			ft_printf("LABEL \"%s\"", str + start);
	}
	else if (head->error == END)
		ft_printf("END \"(null)\"");
	else if (head->error == STRING_AFTER)
		ft_printf("STRING AFTER \"\"\"", str);
	else if (head->error == ENDLINE)
		ft_printf("ENDLINE");
	else if (head->error == DIRECT)
		ft_printf("DIRECT \"%s\"", str + start);
	else if (head->error == DIRECT_LABEL)
		ft_printf("DIRECT_LABEL \"%s\"", str + start);
	else if (head->error == INSTRUCTION)
		ft_printf("INSTRUCTION \"%s\"", str + start);
	else if (head->error == REGISTER)
		ft_printf("REGISTER \"%s\"", str + start);
	else if (head->error == INDIRECT)
		ft_printf("INDIRECT \"%s\"", str + start);
	else if (head->error == COMMAND_NAME)
		ft_printf("COMMAND_NAME \".name\"");
	else if (head->error == COMMAND_COMMENT)
		ft_printf("COMMAND_COMMENT \".comment\"");
	ft_putchar_fd('\n', 2);
	return (0);
}
