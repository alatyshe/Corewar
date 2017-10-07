/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int					move_counter(int pos, int delta_pos)
{
	if ((pos + delta_pos) < MEM_SIZE)
		pos += delta_pos;
	else
		pos += delta_pos - MEM_SIZE;
	return (pos);
}

void				move_pc(t_ps *ps, int delta_pos)
{
	if ((ps->pc + delta_pos) < MEM_SIZE)
		ps->pc += delta_pos;
	else
		ps->pc += delta_pos - MEM_SIZE;
}

int					exec_arg_value(char *map, t_ps *ps, int len)
{
	int				value;

	value = 0;
	while (len)
	{
		value = value | map[ps->pc];
		len--;
		move_pc(ps, 1);
		if (len)
			value = value << 8;
	}
	return (value);
}

unsigned int		get_value(void *buf, int len)
{
	int				j;
	unsigned int	res;

	j = 0;
	res = 0;
	while (j < len)
		res = (res << 8) | (((char *)buf)[j++] & 0x000000ff);
	return (res);
}
