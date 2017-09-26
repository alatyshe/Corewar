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
		ft_putstr_fd("No such label ", 2);
	return (0);
}

int					error_line_char(t_header *head, char *str)
{
	int				end;
	int				start;

	start = skip_spaces(str);
	end = find_chars_in_str(str + start, "\n\t\r\f\v ,\"");
	if (head->error == COUNT)
		ft_printf("[count] for instruction at line %d", head->line);
	else {
		if (end != -1)
			str[end] = '\0';
		ft_printf("[%03d:%03d] ", head->line, head->x + 1);
		if (head->error == LBL_INSTR)
		{
			if (find_chars_in_str(str, ":") < 0)
				ft_printf("INSTRUCTION \"%s\"", str + start);
			else
				ft_printf("LABEL \"%s\"", str + start);
		}
		else if (head->error == END)
			ft_printf("END \"(null)\"", str);
		else if (head->error == STRING_AFTER)
			ft_printf("STRING AFTER \"%s\"", str);
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
	}
	ft_putchar_fd('\n', 2);
	return (0);
}

int					error_arguments(t_header *head, char *read, int x)
{
	x += skip_spaces(read + x);
	if (read[x] == 'r')
		return (error_type(head, INVALID_PAR, REGISTER));
	else if (read[x] == '%')
		return (error_type(head, INVALID_PAR, DIRECT));
	else if (ft_isdigit(read[x]))
		return (error_type(head, INVALID_PAR, INDIRECT));
	else
		return (error_type(head, INVALID_PAR, COUNT));
}

void				print_commands(t_header *head)
{
	t_cmd			*cmd;

	cmd = head->commands;
	printf("head->prog_size : %x\n", head->prog_size);
	if (cmd)
		while (cmd->next)
		{
			printf("%s=====================================%s\n", GREEN, RESET);
			printf("cmd->label :\t|%s|\n", cmd->label);
			// printf("cmd->line :\t|%d|\n", cmd->line);
			printf("cmd->cmd_size :\t|%d|\n", cmd->cmd_size);
			printf("cmd->str :\t|%s|\n", cmd->str);
			printf("\n");
			printf("%02x", cmd->cmd_in_hex);
			if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
				printf("%x", cmd->arg_types);
			printf("|%02x|", cmd->arg[0]->num);
			if (g_tab[cmd->cmd_in_hex - 1].count_arg > 1)
				printf("|%02x|", cmd->arg[1]->num);
			if (g_tab[cmd->cmd_in_hex - 1].count_arg > 2)
				printf("|%02x|", cmd->arg[2]->num);
			printf("\n%s===================================%s\n\n", RED, RESET);
			cmd = cmd->next;
		}
}
