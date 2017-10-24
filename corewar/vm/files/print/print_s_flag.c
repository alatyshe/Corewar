/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_one_cycle(t_map *map)
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

static void		print_d_flag(t_map *map)
{
	if (map->flags->d_flag == 'd' && map->flags->d_value == 0)
	{
		print_one_cycle(map);
		exit(0);
	}
	if (check_flags(map->flags, 'd', map->flags->d_value))
	{
		if (map->cycle % map->flags->d_value == 0)
		{
			print_one_cycle(map);
			exit(0);
		}
	}
}

void			print_map_s_flag(t_map *map)
{
	char		*buf;

	buf = NULL;
	if (check_flags(map->flags, 's', 0) && map->flags->s_value != 0)
	{
		if (map->cycle % map->flags->s_value == 0)
		{
			print_one_cycle(map);
			get_next_line(0, &buf);
			print_d_flag(map);
		}
	}
	print_d_flag(map);
}
