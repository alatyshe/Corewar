/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_aff_cmd(t_map *map, t_ps *ps)
{
	if (map->flags->a_flag == 1)
		ft_printf("Aff: %c\n", ps->reg[ps->arg[0] - 1]);
}

void			cmd_aff(t_map *map, t_ps *ps)
{
	int			pc;

	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_aff_cmd(map, ps);
	print_v_flag_adv(map, ps, pc);
	ps->pc = pc;
	null_commands_variables(ps);
}
