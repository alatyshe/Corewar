/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int				get_variables_idxmod(t_map *all_info, t_ps *ps, int i, int types)
{
	int			pc;
	int			result;
	int			distance;

	result = 0;
	if ((types & ps->arg_types[i]) && ps->arg_types[i] == REG_CODE)
	{
		if (ps->arg[i] < 1 || ps->arg[i] > 16)
		{
			ps->skip_cmd = 1;
			return (0);
		}
		result = ps->reg[ps->arg[i] - 1];
	}
	else if ((types & ps->arg_types[i]) && ps->arg_types[i] == DIR_CODE)
		result = ps->arg[i];
	else if ((types & ps->arg_types[i]) && ps->arg_types[i] == IND_CODE)
	{
		pc = ps->pc;
		distance = ps->arg[i] % IDX_MOD;
		move_map_counter(&pc, distance);
		result = get_value_from_map(all_info, &pc, 4);
	}
	return (result);
}
