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
	ft_printf("%s%s", BOLD_ON, GREEN);
	while (i < 16)
	{
		ft_printf("%5.2d    ", i + 1);
		i++;
	}
	ft_printf("%s%s\n", BOLD_OFF, CYAN);
	i = 0;
	while (i < 16)
	{
		ft_printf("%08x ", ps->reg[i]);
		i++;
	}
	ft_printf("%s\n\n", RESET);
}

void			print_process(t_ps *ps)
{
	if (ps->cmd_in_hex && ps->cycles_to_cmd == 0)
	{
		ft_printf("%s==============================================", YELLOW);
		ft_printf("=====================================================");
		ft_printf("============================================%s\n", RESET);
		if (ps)
		{
			print_registers(ps);
			ft_printf("pc:\t\t\t%s%d\n%s", BOLD_ON, ps->pc, BOLD_OFF);
			ft_printf("command in hex:\t\t%s%02x\n%s", BOLD_ON,
				ps->cmd_in_hex, BOLD_OFF);
			ft_printf("coding byte:\t\t%s%x\n%s", BOLD_ON,
				(g_tab[ps->cmd_in_hex - 1].coding_byte), BOLD_OFF);
			ft_printf("player number:\t\t%s%d\n%s", BOLD_ON,
				ps->player_num, BOLD_OFF);
			ft_printf("carry:\t\t\t%s%d\n%s", BOLD_ON, ps->carry, BOLD_OFF);
			ft_printf("live:\t\t\t%s%d\n%s", BOLD_ON, ps->check_live, BOLD_OFF);
		}
		else
			ft_printf("NULL\n");
		ft_printf("%s==============================================", YELLOW);
		ft_printf("=====================================================");
		ft_printf("============================================%s\n", RESET);
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

void			print_players(t_player *player_in, t_map *map)
{
	t_player	*player;
	int			i;

	i = 1;
	player = player_in;
	ft_printf("\n");
	while (player)
	{
		ft_printf("%s%d Player name:%s\t\t%s\n", GREEN, i, RESET, player->name);
		ft_printf("%sPlayer number:%s\t\t%d\n", GREEN,
			RESET, player->player_num);
		ft_printf("%sLast live:%s\t\t%d\n", GREEN, RESET, player->last_live);
		ft_printf("%sTotal lives:%s\t\t%d\n", GREEN,
			RESET, player->total_lives);
		ft_printf("\n");
		i++;
		player = player->next;
	}
	ft_printf("%stotal_lives:%s\t\t%d\n", GREEN, RESET, map->total_lives);
	ft_printf("%sprocesses:%s\t\t%d\n\n", GREEN, RESET, map->processes);
}
