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

void			print_buf(unsigned char *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while (i < buffer_size)
	{
		printf("[%x]", buffer[i]);
		i++;
	}
	printf("\n");
}

void			print_info(t_info *info)
{
	printf("%s===============================%s\n", GREEN, RESET);
	printf("fileName :\t|%s|\n", info->file_name);
	printf("magic :\t\t%x\n", info->magic);
	printf("progName:\t|%s|\n", info->prog_name);
	printf("prog_size:\t%d\n", info->prog_size);
	printf("prog_comment:\t|%s|\n", info->prog_comment);
	printf("player_num:\t|%d|\n", info->player_num);
	print_buf(info->read, info->prog_size);
	printf("%s===============================%s\n\n", GREEN, RESET);
}

void			print_cmd(t_cmd *cmd)
{
	int			i;

	printf("%s===============================%s\n", RED, RESET);
	printf("%scmd_name: %s\n%s", MAGENTA, cmd->cmd_name, RESET);
	printf("cmd_size :\t%d\n", cmd->cmd_size);
	printf("cmd_in_hex :\t%02x\n", cmd->cmd_in_hex);
	printf("codage_byte:\t%02x\n\n", cmd->codage_byte);
	i = 0;
	while (i < g_tab[cmd->cmd_in_hex - 1].count_arg)
	{
		printf("argument[%d]:\t%-10x", i + 1, cmd->arg[i]);
		printf("%sTYPE : %s", GREEN, RESET);
		if (cmd->arg_types[i] == T_REG)
			printf("T_REG");
		else if (cmd->arg_types[i] == T_DIR)
			printf("T_DIR");
		else if (cmd->arg_types[i] == T_IND)
			printf("T_IND");
		printf("\n");
		i++;
	}
	printf("%s===============================%s\n", RED, RESET);
}

void			print_players(t_player *player)
{
	while (player)
	{
		printf("player_num: %d\n", player->player_num);
		printf("pc: %d\n", player->ps->pc);
		printf("r1: %x\n", player->ps->reg[0]);
		printf("\n");
		player = player->next;
	}
}

void			print_map(t_map *map)
{
	int		i;
	short	mask;

	mask = 255;
	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%02x ", map->map[i] & mask);
		if ((i + 1) % 64 == 0)
			printf("\n");
		i++;
	}
}



