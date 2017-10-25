/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:29:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/25 18:53:47 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int		first_print(char *mem, char *clr, t_file *file, int pl)
{
	int	col;
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 2;
	i = 0;
	col = 241;
	color_proc(clr, file, pl);
	attron(COLOR_PAIR(10));
	attrset(A_NORMAL);
	while (i < 4096)
	{
		x += 3;
		attron(COLOR_PAIR(clr[i]));
		refresh();
		mvprintw(y, x, "%2.2x", 0xff & mem[i]);
		attrset(A_NORMAL);
		if (x > col - 50 && !(x = 0))
			y++;
		i++;
	}
	return (0);
}

char	*create_col(void)
{
	char	*col;
	int		i;

	start_color();
	init_color(COLOR_MAGENTA, 230, 230, 230);
	init_pair(10, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(7, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(8, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(9, COLOR_RED, COLOR_MAGENTA);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	col = malloc(4096);
	i = 0;
	while (i < 4096)
		col[i++] = 11;
	return (col);
}

int		first_print_cykle(int players, t_file *file)
{
	int	y;
	int	pl;

	pl = 1;
	y = 21;
	while (pl < players + 1 && pl < 5)
	{
		attron(COLOR_PAIR(pl));
		mvprintw(y - 13, 200, "___________________________________");
		mvprintw(y - 12, 200, "Player %d %s", pl, file->prog_name);
		mvprintw(y, 200, "___________________________________");
		y += 14;
		pl++;
		file = file->next;
	}
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvprintw(2, 200, "Cycles:");
	mvprintw(3, 200, "Cycles to die:   1536");
	mvprintw(4, 200, "Speed:           1");
	mvprintw(5, 200, "NBR_LIVE:        21");
	mvprintw(6, 200, "MAX_CHECKS:      10");
	attrset(A_NORMAL);
	refresh();
	return (0);
}

void	prepare(char *mem, char *clr, int players, t_file *file)
{
	int	col;
	int	row;

	col = 241;
	row = 68;
	curs_set(0);
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, true);
	create_skelet(col, row);
	first_print(mem, clr, file, players);
	first_print_cykle(players, file);
}

int		visual(t_map *m, int pl, t_file *file)
{
	m->speed = 100000;
	m->speed_v = 1;
	initscr();
	m->clr = create_col();
	prepare(m->map, m->clr, pl, file);
	return (0);
}
