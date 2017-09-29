/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces_before_after_str.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:12:15 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/04 18:26:25 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int					skip_spaces_before_after_str(char *str)
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
