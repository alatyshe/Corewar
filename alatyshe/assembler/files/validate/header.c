/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int			check_symbols_after_quotes(t_header *head,
	char **record, char *read)
{
	char			*second_quote;

	second_quote = ft_strchr(read, '"');
	head->x += find_chars_in_str(read + head->x, "\"") + 1;
	head->x += skip_spaces(read + head->x);
	if (head->x < ft_strlen(read)
		&& (read[head->x] != ';' || read[head->x] != '#'))
	{
		if (read[head->x] == '"')
			error_type(head, SYNTAX_ERROR, STRING_AFTER);
		else
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
		head->error_str = ft_strdup(read + head->x);
	}
	return (0);
}

static int			read_name_comment(t_header *head, char **record,
	char *read)
{
	char			*buff;

	head->line++;
	if (ft_strchr(read, '"') != NULL)
	{
		check_symbols_after_quotes(head, record, read);
		concat_and_free(record, read);
		return (0);
	}
	concat_and_free(record, read);
	concat_and_free(record, "\n");
	return (-1);
}

int					save_header(t_header *head, char **record,
	char *read, int fd)
{
	char			*find_error;
	int				x;
	int				succes;

	if (ft_strchr(read + head->x, '"') == NULL)
	{
		*record = ft_strdup(read);
		while (get_next_line(fd, &read))
		{
			head->x = 0;
			succes = read_name_comment(head, record, read);
			if (head->error == 0)
				head->x = ft_strlen(read);
			free(read);
			read = NULL;
			if (succes >= 0)
				return (succes);
		}
		head->line += check_new_line_at_the_end(fd, &head->x);
		return (error_type(head, SYNTAX_ERROR, END));
	}
	check_symbols_after_quotes(head, record, read);
	*record = ft_strdup(read);
	return (0);
}

int					header(t_header *head, char *read, int fd)
{
	head->x += skip_spaces(read);
	if (read[head->x])
	{
		if (read[head->x] == '#')
			return (0);
		else if (read[head->x] == '.' && ft_strncmp(".name", read + head->x, 5) == SAME)
		{
			head->x += skip_spaces_before_after_str(read + head->x + 1) + 1;
			if (read[head->x] != '"')
				return (error_type(head, SYNTAX_ERROR, ENDLINE));
			head->x++;
			return (save_header(head, &head->prog_name, read, fd));
		}
		else if (read[head->x] == '.' && ft_strncmp(".comment", read + head->x, 7) == SAME)
		{
			head->x = skip_spaces_before_after_str(read + head->x + 1) + 1;
			if (read[head->x] != '"')
				return (error_type(head, SYNTAX_ERROR, ENDLINE));
			head->x++;
			return (save_header(head, &head->prog_comment, read, fd));
		}
		else
			return (error_type(head, SYNTAX_ERROR, LBL_INSTR));
	}
	return (0);
}
