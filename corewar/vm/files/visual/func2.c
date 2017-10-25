/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:07:29 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/25 18:45:49 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void	key_map(t_map *map)
{
	int ch;

	while (1)
	{
		attron(A_BOLD);
		ch = getch();
		if (ch == 32)
			break ;
		if (ch == 261)
			if (map->speed_v < 15 && map->speed_v++)
			{
				mvprintw(4, 217, "      ");
				mvprintw(4, 217, "%d", map->speed_v);
				map->speed /= 2;
			}
		if (ch == 260)
			if (map->speed_v > 0 && map->speed_v--)
			{
				mvprintw(4, 217, "      ");
				mvprintw(4, 217, "%d", map->speed_v);
				map->speed *= 2;
			}
	}
	attrset(A_NORMAL);
}

int		cycle(t_map *map)
{
	int	x;
	int	y;

	x = 217;
	y = 2;
	attron(A_BOLD);
	mvprintw(y, x, "%d", map->cycle);
	attrset(A_NORMAL);
	refresh();
	usleep(map->speed);
	if (getch() == 32)
		key_map(map);
	return (0);
}

int		cycle_to_die(int cycles)
{
	int x;
	int y;

	x = 217;
	y = 3;
	attron(A_BOLD);
	mvprintw(y, x, "      ");
	mvprintw(y, x, "%d", cycles);
	attrset(A_NORMAL);
	refresh();
	return (0);
}

int		position(int num, int *x, int *y)
{
	if (num > 4095 || num < 0)
		return (0);
	*x = (num % 64) * 3 + 3;
	*y = (num / 64) + 2;
	return (1);
}

void	winner(char *s)
{
	int x;
	int y;

	x = 200;
	y = 5;
	mvprintw(y, x, "Winner: %s", s);
	while (getch() == -1)
		;
}
