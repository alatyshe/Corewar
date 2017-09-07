/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:18:42 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:34 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static char		**mem_free(char **res, int j)
{
	int i;

	i = 0;
	while (i < j)
		i++;
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

static size_t	cnt_c(char *str, char sep, int i)
{
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

static size_t	cnt_w(char *str, char sep)
{
	long int	i;
	size_t		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == sep && str[i + 1] != sep) || str[0] != sep)
			j++;
		i++;
	}
	return (j);
}

static char		**array_builder(char const *s, char c, char **res)
{
	long int	fi;
	long int	si;
	long int	i;

	i = 0;
	fi = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			si = 0;
			if (!(res[fi] = (char *)ft_memalloc(cnt_c((char *)s, c, i) + 1)))
				return (mem_free(res, fi));
			while (s[i] != c && s[i])
				res[fi][si++] = s[i++];
			res[fi++][si] = '\0';
		}
	}
	res[fi] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * cnt_w((char *)s, c) + 1)))
		return (NULL);
	res = array_builder(s, c, res);
	return (res);
}
