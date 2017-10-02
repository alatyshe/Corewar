/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_name_and_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					crop_name_and_comment(t_header *head,
	char **save_in, unsigned int len)
{
	char			*first;
	char			*second;

	first = ft_strchr(*save_in, '\"');
	*first++ = '\0';
	second = ft_strchr(first, '\"');
	*second = '\0';
	second = *save_in;
	*save_in = ft_strdup(first);
	free(second);
	if (ft_strlen(*save_in) > len)
	{
		head->error = EMPTY;
		if (len == PROG_NAME_LENGTH)
			return (error_arg(NULL, PROG_NAME_LENGTH, 0, NULL));
		if (len == COMMENT_LENGTH)
			return (error_arg(NULL, COMMENT_LENGTH, 0, NULL));
	}
	return (0);
}
