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

int				main(int argc, char **argv)
{
	t_file		*files;
	int			count_players;

	files = NULL;
	count_players = 0;
	files = read_prog_argv(argc, argv, &count_players);

	print_file(files);
	// print_cmd(files->commands);

	return (0);
}
