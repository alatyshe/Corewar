/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

int				main(int argc, char **argv)
{
	t_file		*files;
	int			count_players;
	t_flags		*flags;

	files = NULL;
	flags = create_flags();
	count_players = 0;
	files = read_arguments(argc, argv, &count_players, flags);
	// print_flags(flags);

	memory_map(files, count_players, flags);
	return (0);
}
