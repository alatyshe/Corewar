/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void			fill_coding_byte(t_cmd *cmd, char code, int arg_num)
{
	if (arg_num == 0)
		cmd->arg_types = ((cmd->arg_types >> 6) | code) << 6;
	else if (arg_num == 1)
		cmd->arg_types = ((cmd->arg_types >> 4) | code) << 4;
	else if (arg_num == 2)
		cmd->arg_types = ((cmd->arg_types >> 2) | code) << 2;
	else if (arg_num == 3)
		cmd->arg_types = (cmd->arg_types | code);
}

static int			get_argument_size(t_header *head, t_cmd *cmd,
	char *read, int arg_num)
{
	int				x;

	x = skip_spaces(read);
	if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_DIR)
		&& read[x] == DIRECT_CHAR && (++x))
	{
		cmd->cmd_size += 2;
		if (g_tab[cmd->cmd_in_hex - 1].flag_direct_size != 1)
			cmd->cmd_size += 2;
		fill_coding_byte(cmd, DIR_CODE, arg_num);
	}
	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_REG)
		&& read[x] == REGISTER_CHAR && (++x))
	{
		cmd->cmd_size += 1;
		fill_coding_byte(cmd, REG_CODE, arg_num);
	}
	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_IND)
		&& (ft_isdigit(read[x]) || read[x] == LABEL_CHAR || read[x] == '-'))
	{
		cmd->cmd_size += 2;
		fill_coding_byte(cmd, IND_CODE, arg_num);
	}
	else
	{
		error_invalid_argument(head, cmd, read + x, arg_num);
		return (x);
	}
	x += check_number(head, read + x);
	return (x);
}

static int			fill_arguments_type(t_header *head, t_cmd *cmd,
	char *read, int id)
{
	int				x;
	int				total_arg;

	total_arg = 0;
	x = skip_spaces(read);
	cmd->cmd_size += 1 + g_tab[id].coding_byte;
	while (total_arg < g_tab[id].count_arg)
	{
		x += get_argument_size(head, cmd, read + x, total_arg++);
		if (head->error != 0)
			return (x);
		if (total_arg < g_tab[id].count_arg)
		{
			if (read[x] == SEPARATOR_CHAR)
				x++;
			else
			{
				error_type(head, SYNTAX_ERROR, LBL_INSTR);
				return (x);
			}
		}
	}
	if (head->error == 0)
		x += check_symbols_after_cmd(head, cmd, read + x);
	return (x);
}

void				command(t_header *head, t_cmd *cmd, char *read)
{
	int				id;
	int				x;

	if (read && read[0] != '\0')
	{
		if (read[0] == COMMENT_CHAR)
			return ;
		id = 15;
		while (id >= 0)
		{
			x = ft_strlen(g_tab[id].name);
			if (ft_strncmp(read, g_tab[id].name, x) == SAME)
			{
				cmd->str = ft_strdup(read + x);
				cmd->cmd_in_hex = g_tab[id].op_code;
				x += fill_arguments_type(head, cmd, read + x, id);
				cmd->x = head->x + x;
				head->x = cmd->x;
				cmd->x = ft_strlen(g_tab[id].name);
				return ;
			}
			id--;
		}
		error_type(head, SYNTAX_ERROR, LBL_INSTR);
	}
}
