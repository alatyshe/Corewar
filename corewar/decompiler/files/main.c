/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/dcmp.h"

int		main(int argc, char **argv)
{
	t_file		*files;
	t_file		*f;
	int			count_players;

	files = NULL;
	count_players = 0;
	files = read_prog_argv(argc, argv, &count_players);
	if (argc == 1)
	{
		ft_printf("Usage: ./asm [-a] <sourcefile.s>\n");
		exit(0);
	}
	f = files;
	while (f)
	{
		writing_to_file(f);
		f = f->next;
	}
	return (0);
}
