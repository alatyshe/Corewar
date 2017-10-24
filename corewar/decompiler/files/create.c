/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/dcmp.h"

t_file			*create_file(void)
{
	t_file		*file;

	file = malloc(sizeof(t_file));
	file->file_name = NULL;
	file->magic = 0;
	file->prog_name = NULL;
	file->prog_size = 0;
	file->prog_comment = NULL;
	file->player_num = 0;
	file->read = NULL;
	file->commands = NULL;
	file->next = NULL;
	return (file);
}

t_cmd			*create_cmd(void)
{
	t_cmd		*cmd;
	int			i;

	i = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd_name = NULL;
	cmd->cmd_size = 0;
	cmd->cmd_in_hex = 0;
	cmd->coding_byte = 0;
	while (i < 3)
	{
		cmd->arg_types[i] = 0;
		cmd->arg[i] = 0;
		i++;
	}
	cmd->next = NULL;
	return (cmd);
}
