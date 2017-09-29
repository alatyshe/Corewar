/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int			ft_read_func(char **str, int fd)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*search;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		search = ft_strjoin(*str, buff);
		free(*str);
		*str = search;
		if ((search = ft_strchr(*str, '\n')) != NULL)
			break ;
	}
	return (ret);
}

static int			return_string(char **str, char **line)
{
	char			*search;

	if ((search = ft_strchr(*str, '\n')) != NULL)
	{
		*search++ = '\0';
		search = ft_strdup(search);
		*line = ft_strdup(*str);
		free(*str);
		*str = search;
		return (1);
	}
	else if ((search = ft_strchr(*str, '\0')) != NULL)
	{
		if (search == *str)
			return (0);
		*line = ft_strdup(*str);
		free(*str);
		*str = ft_strnew(1);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str;

	if (!str)
		str = ft_strnew(1);
	ret = ft_read_func(&str, fd);
	if (ret < 0)
		return (-1);
	return (return_string(&str, line));
}
