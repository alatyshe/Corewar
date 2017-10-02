/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_buf(void *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while (i < buffer_size)
	{
		printf("[%x]", ((char *)buffer)[i]);
		i++;
	}
	printf("\n\n\n\n\n\n\n\n");
}

void			print_info(t_info *info)
{
	printf("%s===============================%s\n", GREEN, RESET);
	printf("fileName :\t%s\n", info->file_name);
	printf("magic :\t\t%x\n", info->magic);
	printf("progName:\t%s\n", info->prog_name);
	printf("prog_size:\t%x\n", info->prog_size);
	printf("prog_comment:\t%s\n", info->prog_comment);
	printf("%s===============================%s\n\n", GREEN, RESET);
}

void			print_cmd(t_cmd *cmd)
{
	int			i;

	printf("%s===============================%s\n", RED, RESET);
	printf("%scmd_name: %s\n%s", MAGENTA, cmd->cmd_name, RESET);
	printf("cmd_size :\t%d\n", cmd->cmd_size);
	printf("cmd_in_hex :\t%x\n", cmd->cmd_in_hex);
	printf("codage_byte:\t%x\n", cmd->codage_byte);
	i = 0;
	while (i < g_tab[cmd->cmd_in_hex - 1].count_arg)
	{
		printf("arg_types[%d]:\t%x\n", i + 1, cmd->arg_types[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < g_tab[cmd->cmd_in_hex - 1].count_arg)
	{
		printf("prog_arg[%d]:\t%x\n", i + 1, cmd->arg[i]->num);
		i++;
	}
	printf("%s===============================%s\n", RED, RESET);
}
