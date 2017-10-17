/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:01:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/03 19:43:21 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int		analiz_arg(t_cmd *cmd, int fd)
{
	if (g_tab[cmd->code - 1].count_arg != 1)
		write(fd, &cmd->arg_types, 1);
	return (0);
}

int		write_cmd(int fd, t_cmd *cmd)
{
	write(fd, &cmd->code, 1);
	analiz_arg(cmd, fd);
	write_arg(fd, cmd);
	return (0);
}

int		write_program(int fd, t_header *header)
{
	t_cmd	*cmd;

	cmd = header->commands;
	while (cmd->next)
	{
		write_cmd(fd, cmd);
		cmd = cmd->next;
	}
	return (0);
}
