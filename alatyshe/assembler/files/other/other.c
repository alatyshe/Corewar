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

#include "../../header/other.h"

int					skip_spaces_before_after_cmd(char *str)
{
	int				i;

	i = 0;
	if (ft_isblank(str[i]))
		while (ft_isblank(str[i]))
			i++;
	if (ft_isalpha(str[i]))
		while (ft_isalpha(str[i]))
			i++;
	if (ft_isblank(str[i]))
		while (ft_isblank(str[i]))
			i++;
	return (i);
}

int					skip_numbers(char *str)
{
	int				i;

	i = 0;

	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int					skip_spaces(char *str)
{
	int				i;

	i = 0;
	if (ft_isblank(str[i]))
		while (ft_isblank(str[i]))
			i++;
	return (i);
}