/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:29:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/23 19:14:18 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/vm.h"

int     create_skelet(int col, int row)
{
    int x;
    int y;

    x = 0;
    y = 0;
    row = 68;
    col = 241;
    while (x < col)
    {
        mvaddch(0, x, ' ' | COLOR_PAIR(10));
        mvaddch(row - 1, x++, ' ' | COLOR_PAIR(10));
    }
    while (y < row)
    {
        mvaddch(y, 0, ' ' | COLOR_PAIR(10));
        mvaddch(y, col - 45, ' ' | COLOR_PAIR(10));
        mvaddch(y++, col - 1, ' ' | COLOR_PAIR(10));
    }
    refresh();
    return (0);
}

int		color_proc(char *clr, t_file *file, int players)
{
	int	pl;
	int	i;
	int	j;
	int	size;

	size = 4096 / players;
	pl = 1;
	i = 0;
	while (file)
	{
		j = i;
		while (j - i < (int)file->prog_size)
			clr[j++] = pl;
		i += size;
		file = file->next;
		pl++;
	}
	return (0);
}

int     first_print(char *mem, char *clr, t_file *file, int pl)
{
    int     col;
    int     row;
    int     x;
    int     y;
    int     i;

    x = 0;
    y = 2;
    i = 0;
    row = 68;
    col = 241;
	color_proc(clr, file, pl);
    attron(COLOR_PAIR(10));
    mvprintw(0, 3, "AND IT FUCK UP");
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

char    *create_col()
{
    char    *col;
    int     i;

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
    col = malloc(4096);
    i = 0;
    while (i < 4096)
        col[i++] = 5;
    return (col);
}

int     first_print_cykle(int players)
{
    int x;
    int y;
    int pl;

    pl = players + 1;
    x = 200;
    y = 20;
    while (players)
    {
        attron(COLOR_PAIR(pl - players));
        mvprintw(y - 14, x, "___________________________________");
        mvprintw(y - 13, x, "Player %d", pl - players);
        mvprintw(y, x, "___________________________________");
        y += 15;
        players--;
    }
    x = 200;
    y = 20;
    attrset(A_NORMAL);
    players = pl - 1;
	mvprintw(2, x, "Cycles:");
	mvprintw(3, x, "Cycles to die:   1536");
	mvprintw(4, x, "Speed: 1");
    while (players--)
    {
        mvprintw(y - 10, x, "Cycles: 0");
        y += 15;
    }
    refresh();
    return (0);
}

void    prepare(char *mem, char *clr, int players, t_file *file)
{
    int col;
    int row;

    col = 241;
    row = 68;
    curs_set(0);
	nodelay(stdscr, TRUE);
 // halfdelay(1);//for getch(); число "1" указывает что чере 1 милисекундy getch() вернет -1
    noecho();
    keypad(stdscr, true);
    create_skelet(col, row);
    first_print(mem, clr, file, players);
    first_print_cykle(players);
}

int     visual(t_map *m, int pl, t_file *file)
{

	m->speed = 100000;
	m->speed_v = 1;
    initscr();
    m->clr = create_col();
    prepare(m->map, m->clr, pl, file);
    //test(mem, clr);//test)
    return (0);
}
