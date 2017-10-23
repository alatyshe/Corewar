/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:41:44 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/20 17:03:44 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"
#include "visual.h"


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

int     put_on_map(int num, int player, char *mem, char *clr)
{
    int x;
    int y;

	if (clr)
	clr[num] = player;
    position(num, &x, &y);
    attron(COLOR_PAIR(player));
    mvprintw(y, x, "%02x", 0xff & mem[num]);
    attrset(A_NORMAL);
    refresh();
    return (0);
}

int     cursor_from_map(int num, char *mem, char *clr)
{
    int x;
    int y;

    position(num, &x, &y);
    attron(COLOR_PAIR(clr[num]));
    mvprintw(y, x, "%02x", 0xff & mem[num]);
    attrset(A_NORMAL);
    refresh();
    return (0);
}

int     cursor_on_map(int num, int player, char *mem, char *clr)
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

int     cycle(int cycles)
{
    int x;
    int y;

    x = 217;
    y = 2;
    mvprintw(y, x, "%d", cycles);
	refresh();
    return (0);
}

int     cycle_to_die(int cycles)
{
    int x;
    int y;

    x = 217;
    y = 3;
    mvprintw(y, x, "      ");
    mvprintw(y, x, "%d", cycles);
	refresh();
    return (0);
}

int     position(int num, int *x, int *y)
{
    if (num > 4095 || num < 0)
        return(0);
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
}
