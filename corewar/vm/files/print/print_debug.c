/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_registers(t_ps *ps)
{
	int		i;

	i = 0;
	printf("REGISTERS :\n%s%s", BOLD_ON, GREEN);
	while (i < 16)
	{
		printf("%5.2d    ", i + 1);
		i++;
	}
	printf("%s%s\n", BOLD_OFF, CYAN);
	i = 0;
	while (i < 16)
	{
		printf("%08x ", ps->reg[i]);
		i++;
	}
	printf("%s\n\n", RESET);
}

void			print_process(t_ps *ps)
{
	if (ps->cmd_in_hex && ps->cycles_to_cmd == 0)
	{
		printf("%s==============================================%s\n", YELLOW, RESET);
		if (ps)
		{
			printf("PS->ProgramCounter:\t%d\n", ps->pc);
			print_registers(ps);
			printf("ps->cmd_in_hex:\t\t%02x\n", ps->cmd_in_hex);
			printf("ps->coding_byte:\t%x\n", (g_tab[ps->cmd_in_hex - 1].coding_byte));
			printf("ps->player_num:\t\t%d\n", ps->player_num);
			printf("ps->carry:\t\t%d\n", ps->carry);
			printf("ps->cycles_to_cmd:\t%d\n", ps->cycles_to_cmd);
			printf("ps->check_live:\t\t%d\n", ps->check_live);
		}
		else
			printf("NULL\n");
		printf("%s==============================================%s\n\n", YELLOW, RESET);
	}
}

void			print_processes(t_ps *ps)
{
	t_ps		*copy_ps;

	copy_ps = ps;
	while (copy_ps)
	{
		print_process(copy_ps);
		copy_ps = copy_ps->next;
	}
}

void			print_players(t_player *player_in)
{
	t_player	*player;
	
	player = player_in;
	while (player)
	{
		printf("%sPLAYER START PLAYER START PLAYER START PLAYER START%s\n", MAGENTA, RESET);
		printf("%sPLAYER->NAME:%s\t\t%s\n", GREEN, RESET, player->name);
		printf("%sPLAYER->PLAYER_NUM:%s\t%d\n", GREEN, RESET, player->player_num);
		printf("%sPLAYER->LAST_LIVE:%s\t%d\n", GREEN, RESET, player->last_live);
		printf("%sPLAYER->TOTAL_LIVES:%s\t%d\n", GREEN, RESET, player->total_lives);
		printf("\n");
		printf("%sPLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END%s\n\n\n", MAGENTA, RESET);
		player = player->next;
	}
}

void			print_info_map(t_map *map)
{
	printf("cycle:\t\t%d\n", map->cycle);
	printf("cycle_to_die:\t\t%d\n", map->cycle_to_die);
	printf("total_lives:\t\t%d\n", map->total_lives);
	printf("processes:\t\t%d\n", map->processes);
	printf("ps_counter:\t\t%d\n\n", map->ps_counter);
}
