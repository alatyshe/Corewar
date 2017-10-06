/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

static void			copy_players_commands_on_map(char *str1, unsigned char *str2, int len)
{
	while (len)
	{
		*str1 = *str2;
		*str1 = *str1;
		*str1++;
		*str2++;
		len--;
	}
}

static void			fill_players(int pos, int num, t_map *map)
{
	t_player	*player;

	player = map->players;
	if (map->players == NULL)
	{
		map->players = create_player();
		player = map->players;
	}
	else
	{
		while (player->next)
			player = player->next;
		player->next = create_player();
		player = player->next;
	}
	player->player_num = num;
	player->ps->map = map;
	player->ps->pc = pos;
	player->ps->reg[0] = num * -1;
	player->ps->player = num;
	player->ps->cycles_to_die = map->cycle_to_die;
}

void				fill_map(t_info *info, t_map *map, int total_players)
{
	int				pos;
	int				distance;
	int				player_num;

	pos = 0;
	player_num = 0;
	distance = MEM_SIZE / total_players;
	while(info)
	{
		player_num++;
		copy_players_commands_on_map(map->map + pos, info->read, info->prog_size);
		fill_players(pos, player_num, map);
		pos += distance;
		info = info->next;
	}	
}