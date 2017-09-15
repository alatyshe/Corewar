/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/other.h"

int					check_label_presence(t_header *head, t_function *function,
	char *read, int fd)
{
	int				x;
	int				error;
	int 			i;

	x = ft_str_find_char(read, ft_isprint);
	if (read[x - 1] == ':')
	{
		read[x - 1] = '\0';
		i = 0;
		// проверка на допустимые символы 
		while (read[i])
		{
			if (!cmp_char_with_str(read[i], LABEL_CHARS))
				return (error_message_type(LEXICAL_ERROR, head, i, EMPTY) + 1);
			i++;
		}
		function->label = ft_strdup(read);
		return (x + 1);
	}
	return (0);
}