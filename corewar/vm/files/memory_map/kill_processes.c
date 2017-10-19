/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		free_process(t_map *map, t_ps *ps)
{
	if (check_flags(map->flags, 'v', 8))
	{
		ft_printf("Process %d has lived for", ps->ps_num);
		ft_printf(" %d cycles (CTD %d)\n", ps->cycles, map->cycle_to_die);
	}
	free(ps->reg);
	free(ps->arg);
	free(ps->arg_types);
	free(ps);
}

void			kill_processes(t_map *map)
{
	t_ps		*ps_before;
	t_ps		*ps_current;
	t_ps		*ps_after;

	ps_before = NULL;
	ps_current = map->ps;
	ps_after = map->ps->next;
	while (ps_current)
	{
		if (ps_current->check_live == 0)
		{
			free_process(map, ps_current);
			if (ps_before)
				ps_before->next = ps_after;
			else
				map->ps = ps_after;
		}
		else
		{
			ps_current->check_live = 0;
			ps_before = ps_current;
		}
		ps_current = ps_after;
		ps_after = (ps_after != NULL) ? ps_after->next : NULL;
	}
}
