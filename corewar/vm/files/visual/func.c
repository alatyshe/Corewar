/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:41:44 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/25 17:10:29 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int		ref(t_map *map)
{
	int	i;
	int x;
	int y;

	i = 0;
	while (i < 4096)
	{
		attron(COLOR_PAIR(map->clr[i]));
		position(i, &x, &y);
		mvprintw(y, x, "%02x", 0xff & map->map[i]);
		attron(A_NORMAL);
		i++;
	}
	return (0);
}

int		put_on_map(int num, int player, char *mem, char *clr)
{
	int x;
	int y;

	if (clr)
		clr[num] = player;
	position(num, &x, &y);
	attron(COLOR_PAIR(player));
	attron(A_BOLD);
	mvprintw(y, x, "%02x", 0xff & mem[num]);
	attrset(A_NORMAL);
	refresh();
	return (0);
}

int		cursor_from_map(int num, char *mem, char *clr)
{
	int	x;
	int	y;

	position(num, &x, &y);
	attron(COLOR_PAIR(clr[num]));
	mvprintw(y, x, "%02x", 0xff & mem[num]);
	attrset(A_NORMAL);
	refresh();
	return (0);
}

int		cursor_on_map(int num, int player, char *mem, char *clr)
{
	int x;
	int y;

	clr = 0;
	position(num, &x, &y);
	attron(COLOR_PAIR(player + 5));
	mvprintw(y, x, "%02x", 0xff & mem[num]);
	attrset(A_NORMAL);
	refresh();
	return (0);
}
