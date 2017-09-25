/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					ft_str_find_char(char *str, int (*f)(int))
{
	int				i;

	i = 0;
	if (str && f)
		while (str[i])
		{
			if (!f(str[i]))
				break ;
			i++;
		}
	return (i);
}

/*
**	поиск хотя бы одного символа из find в str и возврат его позиции
*/

int					find_chars_in_str(char *str, char *find)
{
	int				i;
	int				j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (str[i] == find[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

/*
**	сравнение нужного символа с символами из строки
*/

int					cmp_char_with_str(char c, char *find)
{
	int				i;

	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int					check_new_line_at_the_end(int fd, int *x)
{
	char			buff[1];

	lseek(fd, (long)-1, 2);
	read(fd, buff, 1);
	if (buff[0] == '\n')
	{
		(*x) = 0;
		return (1);
	}
	return (0);
}

void				concat_and_free(char **cmt_cmd, char *read)
{
	char			*buff;

	buff = *cmt_cmd;
	*cmt_cmd = ft_strjoin(*cmt_cmd, read);
	free(buff);
}
