/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

// # include "../../libft/header/libft.h"
// # include "../../libft/header/ft_printf.h"

# include "other.h"
# include "func.h"
# include "op.h"

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_label
{
	char				*name;
	t_functions			*functions;
	struct s_label		*next;
}				t_label;

/*
** fillness_data -  0000 0000 - 00(have progname?)
** 00(have comment?) 00 (?) 00(error)
** line - номер линии на которой находимся
** error - можно записать тип ошибки
*/

typedef struct	s_header
{
	char				fillness_data;
	int					line;
	char				error;
	unsigned int		magic;
	unsigned int		prog_size;
	char				*prog_name;
	char				*comment;
	t_label				*labels;
}				t_header;

t_functions			*create_t_functions();
t_label				*create_t_label();
t_header			*create_t_header();

#endif
