/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

// static int				fill_cmd_size(t_cmd *cmd, char *read, int arg_num)
// {
// 	if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_DIR))
// 		// && read[x] == '%')
// 	{
// 		if (g_tab[cmd->cmd_in_hex - 1].flag_direct_size == 1)
// 			cmd->cmd_size += 2;
// 		else
// 			cmd->cmd_size += 4;
// 	}
// 	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_REG))
// 		// && read[x] == 'r')
// 	{
// 		cmd->cmd_size += 1;
// 	}
// 	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_IND))
// 		// && ft_isdigit(read[x]))
// 	{
// 		cmd->cmd_size += 2;
// 	}
// 	return (x);
// }

int				get_type(t_cmd *cmd, char type, int argc)
{
	if (type == REG_CODE)
	{
		cmd->arg_types[argc] = T_REG;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return (1);
		else
			printf("ERROR TYPE ARGUMENT REG_CODE get_type func\n");
	}
	else if (type == DIR_CODE)
	{
		cmd->arg_types[argc] = T_DIR;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return ((g_tab[cmd->cmd_in_hex - 1].flag_direct_size == 1) ? 2 : 4);
		else
			printf("ERROR TYPE ARGUMENT T_DIR get_type func\n");
	}
	else if (type == IND_CODE)
	{
		cmd->arg_types[argc] = T_IND;
		if (cmd->arg_types[argc] & g_tab[cmd->cmd_in_hex - 1].arg[argc])
			return (2);
		else
			printf("ERROR TYPE ARGUMENT T_IND get_type func\n");
	}
	else
		printf("ERROR get_type func\n");
	return (0);
}

int				get_length_arg(t_cmd *cmd, int argc)
{
	int			len;
	char		type;
	char		mask;

	len = 0;
	mask = 3;
	if (argc == 0)
	{
		type = ((cmd->codage_byte >> 6) & mask);
		len = get_type(cmd, type, argc);
	}
	else if (argc == 1)
	{
		type = ((cmd->codage_byte >> 4) & mask);
		len = get_type(cmd, type, argc);
	}
	else if (argc == 2)
	{
		type = ((cmd->codage_byte >> 2) & mask);
		len = get_type(cmd, type, argc);
	}
	return (len);
}


int				fill_args(void *buf, t_cmd *cmd, int pos_buf, int argc)
{
	int			i;
	int			len;

	i = 0;
	if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
	{
		len = get_length_arg(cmd, argc);
		cmd->arg[argc]->num = get_value(buf + pos_buf, len);
		i += len;
	}
	else
	{
		len = (g_tab[cmd->cmd_in_hex - 1].flag_direct_size == 1) ? 2 : 4;
		cmd->arg[0]->num = get_value(buf + pos_buf, len);
		i += len;
	}
	cmd->cmd_size += i;
	return (i);
}

t_cmd			*cmd_reading(void *buf, t_cmd *cmd, int pos_buf)
{
	int			argc;

	argc = 0;
	if (((char*)buf)[pos_buf] >= 1 && ((char*)buf)[pos_buf] <= 16)
	{
		if (cmd == NULL)
			cmd = create_cmd(g_tab[(((char*)buf)[pos_buf] - 1)].count_arg);
		cmd->cmd_in_hex = ((char*)buf)[pos_buf++];
		cmd->cmd_name = ft_strdup(g_tab[cmd->cmd_in_hex - 1].name);
		cmd->cmd_size++;
		if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
		{
			cmd->cmd_size++;
			cmd->codage_byte = ((char*)buf)[pos_buf++];
		}

		while (argc < g_tab[cmd->cmd_in_hex - 1].count_arg)
		{
			pos_buf += fill_args(buf, cmd, pos_buf, argc);
			argc++;
		}
		print_cmd(cmd);
		cmd_reading(buf, cmd->next, pos_buf);
		
	}
	return (0);
}

void			analyzing_buf(void *buf, int buf_size, t_info *info, char *file)
{
	int			j;

	j = 0;
	info->file_name = ft_strdup(file);
	info->magic = magic_reading(buf, info);
	info->prog_name = name_reading(buf, info);
	info->prog_size = size_reading(buf, info);
	info->prog_comment = comment_reading(buf, info);
	print_info(info);
	j = sizeof(unsigned int) + PROG_NAME_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	j = j + sizeof(unsigned int) + COMMENT_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	info->commands = cmd_reading(buf, info->commands, j);
}

int				main(int argc, char **argv)
{
	int		i;
	t_info	*info;
	t_info	*begin;

	i = 1;
	info = create_info();
	begin = info;
	while (i < argc)
	{
		if (info == NULL)
			info = create_info();
		reading(argv[i], info);
		info = info->next;
		i++;
	}
	return (0);
}