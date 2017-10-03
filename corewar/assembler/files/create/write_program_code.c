/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:01:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/09/12 16:02:06 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/create.h"


int 	analiz_arg(t_cmd *cmd, int fd)
{
	if (g_tab[cmd->code - 1].count_arg != 1)
		write(fd, &cmd->arg_types, 1);
	return (0);
}

int		write_cmd(int fd,t_header *header, t_cmd *cmd)
{
	write(fd, &cmd->code, 1);
	analiz_arg(cmd, fd);
	write_arg(fd, header, cmd);
	return (0);
}

int 	write_program(int fd, t_header *header)
{
	t_cmd	*cmd;

	cmd = header->commands;
	while (cmd->next)
	{
		write_cmd(fd, header, cmd);
		cmd = cmd->next;
	}
	return (0);
}

