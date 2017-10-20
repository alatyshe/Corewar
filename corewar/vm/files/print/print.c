/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_one_cycle(t_map *map)
{
	int			i;
	short		mask;

	mask = 255;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("0x0000 : ");
		if (i != 0 && i % 64 == 0)
			ft_printf("%#06x : ", i);
		ft_printf("%02x ", map->map[i] & mask);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
}

void			print_one_cycle_for_j(t_map *map)
{
	int			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%02x ", map->map[i] & 255);
		i++;
	}
}

void			print_map_java(t_map *map, t_file *file)
{
	int			i;
	int			players;
	t_file		*copy_file;

	i = 0;
	players = 1;
	copy_file = file;
	while (copy_file)
	{
		ft_printf("%d:%d:", players, copy_file->prog_size);
		ft_printf("%s:%s;", copy_file->prog_name, copy_file->prog_comment);
		copy_file = copy_file->next;
		players++;
	}
	ft_printf("\n");
	while (i < MEM_SIZE)
		ft_printf("%02x ", 255 & map->map[i++]);
	ft_printf("\n");
}

void			print_map(t_map *map)
{
	char		*buf;

	buf = NULL;
	if (check_flags(map->flags, 's', 0))
	{
		if (map->cycle % map->flags->s_value == 0)
		{
			print_one_cycle(map);
			get_next_line(0, &buf);
		}
	}
	else if (check_flags(map->flags, 'j', 0))
	{
		print_one_cycle_for_j(map);
	}
}

void			introducing_print(t_file *file)
{
	t_file		*player;
	int			i;

	i = 1;
	player = file;
	ft_printf("Introducing contestants...\n");
	while (player)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, player->prog_size, player->prog_name, player->prog_comment);
		i++;
		player = player->next;
	}
}
