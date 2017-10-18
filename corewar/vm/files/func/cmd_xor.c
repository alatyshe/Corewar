/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_xor_cmd(t_map *map, t_ps *ps);

void			cmd_xor(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_xor_cmd(map, ps);

	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		printf("\n");
	}

	ps->pc = pc;
	
	null_commands_variables(ps);
}

static void		execute_xor_cmd(t_map *map, t_ps *ps)
{
	int			*value;
	int			res;
	int			i;

	i = 0;
	value = (int *)malloc(sizeof(int) * g_tab[7].count_arg);
	while (i < g_tab[7].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			free(value);
			return ;
		}
		i++;
	}
	res = value[FIRST_ARG] ^ value[SECOND_ARG];
	if (!res)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[THIRD_ARG] - 1] = res;
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s %d %d r%d\n", ps->ps_num, "xor", value[FIRST_ARG], value[SECOND_ARG], ps->arg[2]);
	free(value);
}

