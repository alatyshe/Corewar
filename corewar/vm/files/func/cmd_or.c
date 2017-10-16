/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_or_cmd(t_map *map, t_ps *ps);

void			cmd_or(t_map *map, t_ps *ps)
{
	int			pc;

	// проверка кодирующего бита
	
	// printf("%sOR HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_or_cmd(map, ps);
	
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_or_cmd(t_map *map, t_ps *ps)
{
	int			value[g_tab[6].count_arg];
	int			res;
	int			i;

	i = 0;
	while (i < g_tab[6].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i, g_tab[6].arg[i]);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			return ;
		}
		i++;
	}
	res = value[FIRST_ARG] | value[SECOND_ARG];
	if (!res)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[THIRD_ARG] - 1] = res;
	if (check_flags(map->flags, 'v', 4))
		ft_printf("P    %-d | %s %d %d r%d\n", ps->ps_num, "or",
			value[FIRST_ARG], value[SECOND_ARG], ps->arg[2]);
}