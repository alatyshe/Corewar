/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:48:46 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/11 18:44:42 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		infin(char *mem, char *clr)
{
	int     col;
	int     row;
	int     x;
	int     y;
	int     i;
	int		i1;
	int		x1;
	int		y1;
	int		cykles1;
	int 	cykles2;

	cykles1 = 0;
	cykles2 = 256;
	x = 0;
	y = 2;
	i = 0;
	i1 = 2048;
	x1 = (i1 % 64) * 3; // +3 ? 
	y1 = (i1 / 64) + 2;

	//getmaxyx(stdscr, row, col);
	row = 68;
	col = 241;
	while(getch())
	{
		if (i > 4096 || y > row - 1)
		{
			x = 0;
			i = 0;
			y = 2;
		}
		if (i1 > 4096 || y1 > row - 1)
		{
			x1 = 0;
			i1 = 0;
			y1 = 2;
		}
		x += 3;
		x1 += 3;

		//	attron(COLOR_PAIR(1));
		//	mvprintw(y, x + 3, "%02x", mem[i + 1]);
		attron(COLOR_PAIR(clr[i]));
		mvaddch(y, x + 3, ' ' | COLOR_PAIR(10));
		mvaddch(y, x + 4, ' ' | COLOR_PAIR(10));
		mvprintw(y, x, "%02x", mem[i++]);
		if (x > col - 50 && !(x = 0))
			y++;
		attron(COLOR_PAIR(clr[i1]));
		mvaddch(y1, x1 + 3, ' ' | COLOR_PAIR(10));
		mvaddch(y1, x1 + 4, ' ' | COLOR_PAIR(10));
		mvprintw(y1, x1, "%02x", mem[i1++]);
		if (x1 > col - 50 && !(x1 = 0))
			y1++;
		attrset(A_NORMAL);
		cykle(cykles1++, 1, mem, clr);
		cykle(cykles2++, 3, mem, clr);
	}
	refresh();
	return (0);
}

int		test(char *mem, char *clr)
{
	int     i = 0;
	char    j = 0x3f;

	while (i < 10)
	{
		clr[i++] = 1;
		j += 2;
	}
	while(i < 4096)
	{
		if (i == 2048)
			while(i < 2058)
				clr[i++] = 3;
		i++;
	}
	mem[64] = 0x2f;
	put_on_map(64, 4, mem, clr);
	put_on_map(67, 1, mem, clr);
	put_on_map(0, 2, mem, clr);
	cursor_on_map(1, 3, mem, clr);//зеленый
	put_on_map(1, 3, mem, clr);//синий - ставит свой цвет
	cursor_on_map(1, 3, mem, clr);//синий
	cykle(456, 3, mem, clr);
	infin(mem, clr);//for fun
	while(getch());
	return(0);
}

int		main()
{
	char	*test = malloc(4096);
	int		i = 0;
	char	j = 0x3f;

	while (i < 10)
	{
		test[i++] = j;
		j += 2;
	}
	while(i < 4096)
	{
		test[i++] = 0;
		if (i == 2048)
			while(i < 2058)
			{
				test[i++] = j++;
			}
	}
	visual(test); //функция запуска!
	endwin();//in the end of programm!
	return (0);
}
