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

int					return_pc(int current_pos, int delta_pos)
{
	if ((current_pos + delta_pos) < MEM_SIZE)
		return (current_pos + delta_pos);
	else
		return (current_pos + delta_pos - MEM_SIZE);
}

int					check_command(t_ps *ps, t_map *map)
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
	int				i;

	i = 0;
	if (check_command(ps, map))
		i = return_pc(ps->pc, 1);
	printf("%x\n", ps->reg[0]);
	return (i);
}

void				start_processes(t_map *map)
{
	t_player	*p;
	t_ps		*ps;

	p = map->players;
	while (p)
	{
		ps = p->ps;
		// return_color(p->player_num);
		while (ps)
		{
			ps->pc = executing_ps(ps, map);
			ps = ps->next;
		}
		// printf("%s", RESET);
		p = p->next;
	}
}

void				memory_map(t_info *info, int total_players)
{
	t_map			*map;
	int				pos;
	int				distance;
	int				player_num;

	map = create_map();
	fill_map(info, map, total_players);
	
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
	count_players = 0;
	files = read_arguments(argc, argv, &count_players);
	memory_map(files, count_players);
	return (0);
}
