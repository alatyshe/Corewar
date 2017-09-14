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

static int			read_cmd_cmt(t_header *head, char **cmt_cmd, char *read)
{
	int				x;
	char			*pos;
	char			*buff;

	head->line++;
	if ((pos = ft_strchr(read, '"')) != NULL)
	{
		*pos++ = '\0';
		x = skip_spaces(pos);
		if (x < ft_strlen(pos) && pos[x] != ';')
		{
			if (pos[x] == '"')
				error_message_type(SYNTAX_ERROR, head, x, STRING_AFTER);
			else
				error_message_type(SYNTAX_ERROR, head, x, LBL_INSTR);
			head->error_string = ft_strdup(pos + x);
			return (ft_strlen(read) + x + 2);
		}
		concat_and_free(cmt_cmd, read);
		return (0);
	}
	concat_and_free(cmt_cmd, read);
	concat_and_free(cmt_cmd, "");
	return (-1);
}

static int			check_symbols_after_quotes(t_header *head, char **cmt_cmd,
	char *read, char *pos)
{
	int				x;

	*pos++ = '\0';
	x = skip_spaces(pos) + 1;
	if (x < ft_strlen(pos) && pos[x] != ';')
	{
		head->error_string = ft_strdup(pos + x);
		error_message_type(SYNTAX_ERROR, head, x, LBL_INSTR);
		return (ft_strlen(read) + x + 2);
	}
	*cmt_cmd = ft_strdup(read);
	return (0);
}

int					save_command(t_header *head, char **cmt_cmd,
	char *read, int fd)
{
	char			*pos;
	char			*find_error;
	int				x;
	int				succes;

	if ((pos = ft_strchr(read, '"')) == NULL)
	{
		*cmt_cmd = ft_strdup(read);
		while (get_next_line(fd, &read))
		{
			succes = read_cmd_cmt(head, cmt_cmd, read);
			x = ft_strlen(read) + 1;
			free(read);
			read = NULL;
			if (succes >= 0)
				return (succes);
		}
		head->line += check_new_line_at_the_end(fd, &x);
		return (error_message_type(SYNTAX_ERROR, head, x, END));
	}
	else
		check_symbols_after_quotes(head, cmt_cmd, read, pos);
	return (0);
}

int					check_comment_name(t_header *head, char *read, int fd)
{
	int				x;

	x = skip_spaces(read);
	if (read[x])
	{
		if (read[x] == '#')
			return (0);
		else if (read[x] == '.' && ft_strncmp(".name", read + x, 5) == SAME)
		{
			x = skip_spaces_before_after_cmd(read + x + 1) + 1;
			if (read[x] != '"')
				return (error_message_type(SYNTAX_ERROR, head, x + 1, ENDLINE));
			return (save_command(head, &head->prog_name, read + x + 1, fd));
		}
		else if (read[x] == '.' && ft_strncmp(".comment", read + x, 7) == SAME)
		{
			x = skip_spaces_before_after_cmd(read + x + 1) + 1;
			if (read[x] != '"')
				return (error_message_type(SYNTAX_ERROR, head, x + 1, ENDLINE));
			return (save_command(head, &head->prog_comment, read + x + 1, fd));
		}
		else
			return (error_message_type(SYNTAX_ERROR, head, x + 1, LBL_INSTR));
	}
	return (0);
}
