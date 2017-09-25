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

void				fill_coding_byte(t_cmd *cmd, char code, int arg_num)
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

int					fill_cmd_size(t_header *head, t_cmd *cmd,
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
		printf("ERROR\n");
	while (read[x] && read[x] != ',' && !ft_isblank(read[x]))
		x++;
	x += skip_spaces(read + x);
	return (x);
}

int					fill_command(t_header *head, t_cmd *cmd, char *read, int id)
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
				return (error_arguments(head, read, x));
		}
	}
	return (x);
}

int					check_command(t_header *head, t_cmd *cmd, char *read)
{
	int				i;
	int				name_len;

	if (read && read[0] != '\0')
	{
		if (read[0] == '#')
			return (1);
		i = 15;
		while (i >= 0)
		{
			name_len = ft_strlen(g_tab[i].name);
			if (ft_strncmp(read, g_tab[i].name, name_len) == SAME)
			{
				cmd->str = ft_strdup(read + name_len);
				cmd->line = head->line;
				return (fill_command(head, cmd, read + name_len, i) + name_len);
			}
			i--;
		}
	}
	return (-1);
}

int					get_command(t_header *head, t_cmd *cmd,
	char *read, int fd)
{
	char			*str;
	int				x;
	int				i;

	if (!read[0])
	{
		while (get_next_line(fd, &str))
		{
			x = skip_spaces(str);
			if ((i = check_command(head, cmd, str + x)) > 0)
				return (x + i);
		}
	}
	else
		return (check_command(head, cmd, read));
	return (1);
}
