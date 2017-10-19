/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		copy_players_commands_on_map(char *str1,
	unsigned char *str2, int len)
{
	while (len)
	{
		*str1++ = *str2++;
		len--;
	}
}

static void		crate_and_fill_players(t_map *map, char *name, int num)
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
	player->name = ft_strdup(name);
	player->player_num = num * -1;
}

static void		put_processes_on_map(t_file *copy_file, t_map *map,
	int pos, int player_num)
{
	t_ps		*process;

	process = NULL;
	if (map->ps == NULL)
	{
		map->ps = create_ps(pos, -player_num, map->ps_counter);
		map->winner = copy_file->prog_name;
	}
	else
	{
		process = create_ps(pos, -player_num, map->ps_counter);
		process->next = map->ps;
		map->ps = process;
	}
}

void			fill_map(t_file *file, t_map *map, int total_players)
{
	int			pos;
	int			distance;
	int			player_num;
	t_file		*copy_file;

	pos = 0;
	player_num = 0;
	copy_file = file;
	distance = MEM_SIZE / total_players;
	while (copy_file)
	{
		player_num++;
		copy_players_commands_on_map(map->map + pos,
			copy_file->read, copy_file->prog_size);
		crate_and_fill_players(map, copy_file->prog_name, player_num);
		put_processes_on_map(copy_file, map, pos, player_num);
		map->ps->reg[0] = -player_num;
		map->ps_counter++;
		pos += distance;
		copy_file = copy_file->next;
	}
}
