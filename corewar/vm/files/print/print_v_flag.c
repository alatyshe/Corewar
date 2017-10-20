/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_v_flag_adv(t_map *map, t_ps *ps, int pc)
{
	int			temp_pc;

	temp_pc = ps->pc;
	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			ft_printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		ft_printf("\n");
	}
}