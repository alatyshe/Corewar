/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/other.h"

int					check_fuctions_a(t_header *head, t_function *function,
	char *read)
{
	if (ft_strncmp(read, "add", 3) == SAME)
		printf("ADD\n");
	else if (ft_strncmp(read, "and", 3) == SAME)
		printf("AND\n");
	else if (ft_strncmp(read, "aff", 3) == SAME)
		printf("AFF\n");
	else
		return (0);
	return (1);
}

int					check_fuctions_l(t_header *head, t_function *function,
	char *read)
{
	if (ft_strncmp(read, "ldi", 3) == SAME)
		printf("LDI\n");
	else if (ft_strncmp(read, "live", 4) == SAME)
		printf("LIVE\n");
	else if (ft_strncmp(read, "ld", 2) == SAME)
		printf("LD\n");
	else if (ft_strncmp(read, "lld", 3) == SAME)
		printf("LLD\n");
	else if (ft_strncmp(read, "lldi", 4) == SAME)
		printf("LLDI\n");
	else if (ft_strncmp(read, "lfork", 5) == SAME)
		printf("LFORK\n");
	else
		return (0);
	return (1);
}

int					check_fuctions_x(t_header *head, t_function *function,
	char *read)
{
	if (ft_strncmp(read, "st", 2) == SAME)
		printf("ST\n");
	else if (ft_strncmp(read, "sti", 3) == SAME)
		printf("STI\n");
	else if (ft_strncmp(read, "sub", 3) == SAME)
		printf("SUB\n");
	else
		return (0);
	return (1);
}

int					check_function(t_header *head, t_function *function, char *read)
{
	if (!read[0])
	{
		if (read[0] == '#')
			return(1);
		else if (read[0] == 'a')
			return (check_fuctions_a(head, function, read));
		else if (read[0] == 'l')
			return (check_fuctions_l(head, function, read));
		else if (read[0] == 's')
			return (check_fuctions_x(head, function, read));
		else if (ft_strncmp(read, "fork", 4) == SAME)
			printf("FORK\n");
		else if (ft_strncmp(read, "or", 2) == SAME)
			printf("OR\n");
		else if (ft_strncmp(read, "zjmp", 4) == SAME)
			printf("ZJMP\n");
		else if (ft_strncmp(read, "xor", 3) == SAME)
			printf("XOR\n");
		else
			return (0);
	}
	return (-1);
}

int					fill_function(t_header *head, t_function *function,
	char *read, int fd)
{
	char			*str;
	int				x;

	x = skip_spaces(read);
	if (!read[0])
	{
		while (get_next_line(fd, &str))
		{
			if (check_function(head, function, str + x) >= 0)
				return (0);
		}
	}

	return (1);
}