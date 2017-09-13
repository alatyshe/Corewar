/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmt_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int						save_command(t_header *head, char **save_in, char *str, int fd)
{
	char				*pos;
	char				*find_error;
	int 				x;

	if ((pos = ft_strchr(str, '"')) == NULL)
	{
		*save_in = ft_strjoin("", str);
		while (get_next_line(fd, &str))
		{
			head->line++;
			if ((pos = ft_strchr(str, '"')) != NULL)
			{
				*pos++ = '\0';
				x = skip_spaces(pos);
				if (x < ft_strlen(pos) && pos[x] != ';')
				{
					error_message_type(SYNTAX_ERROR, head, x);
					head->error_string = ft_strdup(pos + x);
					return (ft_strlen(str) + x + 2);
				}
				*save_in = ft_strjoin(*save_in, str);	//	leaks
				return (0) ;
			}
			else
			{
				*save_in = ft_strjoin(*save_in, str);	//	leaks
				*save_in = ft_strjoin(*save_in, "\n");	//	leaks
			}
		}
		get_next_line(fd, &str);
		x = ft_strlen(str) + 1;
		error_message_type(SYNTAX_ERROR, head, x);
		head->error = 2;
		return (x);
	}
	else
	{
		*pos++ = '\0';
		x = skip_spaces(pos) + 1;
		if (x < ft_strlen(pos) && pos[x] != ';')
		{
			head->error_string = ft_strdup(pos + x);
			error_message_type(SYNTAX_ERROR, head, x);
			return (ft_strlen(str) + x + 2);
		}
		*save_in = ft_strdup(str);
	}
	return (0);
}

int					check_comment_name(t_header *head, char *str, int fd)
{
	int				x;

	x = skip_spaces(str); 
	if (str[x])
	{
		if (str[x] == '#')
			return (0);
		else if (str[x] == '.' && ft_strncmp(".name", str + x, 5) == SAME)
		{
			x = skip_spaces_before_after_cmd(str + x + 1) + 1;
			if (str[x] != '"')
				return (error_message_type(LEXICAL_ERROR, head, x));
			x++;
			return (save_command(head, &head->prog_name, str + x, fd));
		}
		else if (str[x] == '.' && ft_strncmp(".comment", str + x, 7) == SAME)
		{
			x = skip_spaces_before_after_cmd(str + x + 1) + 1;
			if (str[x] != '"')
				return (error_message_type(LEXICAL_ERROR, head, x));
			x++;
			return (save_command(head, &head->prog_comment, str + x, fd));
		}
		else
			return (error_message_type(SYNTAX_ERROR, head, x));
	}
	return (0);
}