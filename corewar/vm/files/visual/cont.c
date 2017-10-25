/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:44:59 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/25 16:47:13 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int		create_skelet(int col, int row)
{
	int	x;
	int	y;

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
	int pl;
	int i;
	int j;
	int size;

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
