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

static int				fill_cmd_size(t_header *head, t_cmd *cmd,
	char *read, int arg_num)
{
	int				x;

	x = skip_spaces(read);
	if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_DIR)
		&& read[x] == '%')
	{
		if (g_tab[cmd->cmd_in_hex - 1].flag_direct_size == 1)
			cmd->cmd_size += 2;
		else
			cmd->cmd_size += 4;
		fill_coding_byte(cmd, DIR_CODE, arg_num);
	}
	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_REG)
		&& read[x] == 'r')
	{
		cmd->cmd_size += 1;
		fill_coding_byte(cmd, REG_CODE, arg_num);
	}
	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_IND)
		&& ft_isdigit(read[x]))
	{
		cmd->cmd_size += 2;
		fill_coding_byte(cmd, IND_CODE, arg_num);
	}
	else
		error_type(head, SYNTAX_ERROR, ENDLINE);
	while (read[x] && read[x] != ',' && !ft_isblank(read[x]))
		x++;
	x += skip_spaces(read + x);
	return (x);
}

static int			fill_arguments_type(t_header *head, t_cmd *cmd, char *read, int id)
{
	int				x;
	int				total_arg;

	total_arg = 0;
	x = skip_spaces(read);
	cmd->cmd_in_hex = g_tab[id].op_code;
	cmd->cmd_size += 1 + g_tab[id].coding_byte;
	while (total_arg < g_tab[id].count_arg)
	{
		x += fill_cmd_size(head, cmd, read + x, total_arg++);
		if (total_arg < g_tab[id].count_arg)
		{
			if (read[x] == ',')
				x++;
			else
			{
				head->x += x;
				return (error_arguments(head, read, x));
			}
		}
	}
	return (x);
}

void				command(t_header *head, t_cmd *cmd, char *read)
{
	int				id;
	int				name_len;
	int				x;

	x = 0;
	if (read && read[0] != '\0')
	{
		if (read[0] == '#')
			return ;
		id = 15;
		while (id >= 0)
		{
			name_len = ft_strlen(g_tab[id].name);
			if (ft_strncmp(read, g_tab[id].name, name_len) == SAME)
			{
				x += name_len;
				cmd->str = ft_strdup(read + name_len);
				cmd->line = head->line;
				x += fill_arguments_type(head, cmd, read + name_len, id);
				if (head->error == 0)
					check_symbols_after_cmd(head, read + x);
				head->x += x;
				return ;
			}
			id--;
		}
	}
}
