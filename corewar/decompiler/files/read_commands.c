/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/dcmp.h"

static int		get_type(t_cmd *cmd, char type, int argc)
{
	if (type == REG_CODE)
	{
		cmd->arg_types[argc] = T_REG;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return (g_sizes[(int)cmd->cmd_in_hex][REG_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_REG get_type func\n", 2);
	}
	else if (type == DIR_CODE)
	{
		cmd->arg_types[argc] = T_DIR;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return (g_sizes[(int)cmd->cmd_in_hex][DIR_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_DIR get_type func\n", 2);
	}
	else if (type == IND_CODE)
	{
		cmd->arg_types[argc] = T_IND;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return (g_sizes[(int)cmd->cmd_in_hex][IND_CODE]);
		ft_putstr_fd("ERROR TYPE ARGUMENT T_IND get_type func\n", 2);
	}
	else
		ft_putstr_fd("ERROR get_type func\n", 2);
	exit(0);
}

static int		get_length_arg(t_cmd *cmd, int argc)
{
	int			len;
	char		type;
	char		mask;

	len = 0;
	mask = 3;
	if (argc == 0)
		type = ((cmd->coding_byte >> 6) & mask);
	else if (argc == 1)
		type = ((cmd->coding_byte >> 4) & mask);
	else if (argc == 2)
		type = ((cmd->coding_byte >> 2) & mask);
	else
		type = cmd->coding_byte & mask;
	len = get_type(cmd, type, argc);
	return (len);
}

int				fill_args(unsigned char *buf, t_cmd *cmd, int pos_buf, int argc)
{
	int			len;

	len = 0;
	if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
		len = get_length_arg(cmd, argc);
	else
		len = g_sizes[(int)cmd->cmd_in_hex][DIR_CODE];
	cmd->arg[argc] = get_value_from_file(buf + pos_buf, len);
	cmd->cmd_size += len;
	return (len);
}

t_cmd			*read_commands(unsigned char *buf, int pos_buf, int file_len)
{
	int			argc;
	t_cmd		*cmd;

	argc = 0;
	if (pos_buf < file_len
		&& buf[pos_buf] >= 1 && buf[pos_buf] <= 16)
	{
		cmd = create_cmd(g_tab[(((char*)buf)[pos_buf] - 1)].count_arg);
		cmd->cmd_in_hex = ((char*)buf)[pos_buf++];
		cmd->cmd_name = ft_strdup(g_tab[cmd->cmd_in_hex - 1].name);
		cmd->cmd_size++;
		if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
		{
			cmd->cmd_size++;
			cmd->coding_byte = ((char*)buf)[pos_buf++];
		}
		while (argc < g_tab[cmd->cmd_in_hex - 1].count_arg)
		{
			pos_buf += fill_args(buf, cmd, pos_buf, argc);
			argc++;
		}
		cmd->next = read_commands(buf, pos_buf, file_len);
		return (cmd);
	}
	return (NULL);
}
