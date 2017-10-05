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

void				mem_copy(char *str1, unsigned char *str2, int len)
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

void				fill_players(int pos, int num, t_map *map)
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

int					return_pc(int current_pos, int delta_pos)
{
	if ((current_pos + delta_pos) < MEM_SIZE)
		return (current_pos + delta_pos);
	else
		return (current_pos + delta_pos - MEM_SIZE);
}

int					it_is_not_command(t_ps *ps, t_map *map)
{
	int		pos_buf;

	pos_buf = ps->pc;
	printf("map[pos_buf]: %x\n", map->map[pos_buf]);

	if (map->map[pos_buf] >= 1 && map->map[pos_buf] <= 16)
	{
		printf("!!!!!!!!!!!!!!\n");				//here - detection of functions!
	}
	return (0);
}

int					executing_ps(t_ps *ps, t_map *map)
{
	if (it_is_not_command(ps, map))
		ps->pc = return_pc(ps->pc, 1);
	printf("%x\n", ps->reg[0]);
	return (0);
}

void				return_color(int n)
{
	if (n == 1)
		printf("%s", RED);
	else if (n == 2)
		printf("%s", GREEN);
	else if (n == 3)
		printf("%s", YELLOW);
	else if (n == 4)
		printf("%s", BLUE);
	else if (n == 5)
		printf("%s", MAGENTA);
	else if (n == 6)
		printf("%s", CYAN);
	else
		printf("%s", BLACK);

}

void				start_processes(t_map *map)
{
	t_player	*p;
	t_ps		*ps;

	p = map->players;
	while (p)
	{
		ps = p->ps;
		return_color(p->player_num);
		while (ps)
		{
			ps->pc = executing_ps(ps, map);
			ps = ps->next;
		}
		printf("%s", RESET);
		p = p->next;
	}
}

void				memory_map(t_info *info, int total_players)
{
	t_map			*map;
	int				pos;
	int				distance;
	int				player_num;

	player_num = 0;
	map = create_map();
	pos = 0;
	distance = MEM_SIZE / total_players;
	while(info)
	{
		player_num++;
		mem_copy(map->map + pos, info->read, info->prog_size);
		fill_players(pos, player_num, map);
		pos += distance;
		info = info->next;
	}
	print_map(map);
	print_players(map->players);
	start_processes(map);
}

int				main(int argc, char **argv)
{
	t_info		*files;
	t_info		*copy_files;
	int			count_players;

	files = NULL;
	files = read_arguments(argc, argv);
	count_players = 0;
	copy_files = files;
	while (copy_files)
	{
		copy_files = copy_files->next;
		count_players++;
		if (count_players > MAX_PLAYERS)
		{
			ft_putstr_fd("Too many champions\n", 2);
			exit(0);
		}
	}
	memory_map(files, count_players);
	return (0);
}
