/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					crop_name_comment(t_header *head)
{
	char			*first;
	char			*second;
	int				indicator;

	first = ft_strchr(head->prog_name, '\"');
	*first++ = '\0';
	second = ft_strchr(first, '\"');
	*second = '\0';
	second = head->prog_name;
	head->prog_name = ft_strdup(first);
	free(second);
	first = ft_strchr(head->prog_comment, '\"');
	*first++ = '\0';
	second = ft_strchr(first, '\"');
	*second = '\0';
	second = head->prog_comment;
	head->prog_comment = ft_strdup(first);
	free(second);
	if ((ft_strlen(head->prog_name) > 128 && (indicator = 1))
		|| (ft_strlen(head->prog_comment) > 2048 && (indicator = 2)))
	{
		head->error = EMPTY;
		if (indicator == 1)
			return (error_arguments(NULL, PROG_NAME_LENGTH, 0, NULL));
		if (indicator == 2)
			return (error_arguments(NULL, COMMENT_LENGTH, 0, NULL));
	}
	return (0);
}