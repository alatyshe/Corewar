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

# include "other.h"
# include "func.h"
# include "op.h"
# include "asm.h"

/*
** fillness_data -  0000 0000 - 00(have progname?)
** 00(have comment?) 00 (?) 00(error)
** line - номер линии на которой находимся
** error - можно записать тип ошибки
*/

typedef struct	s_header
{
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*comment;
	char				error;
	t_label				*labels;
}				t_header;

t_label				*create_t_label();
t_function			*create_t_function();
t_arg				*create_t_arg();
t_header			*create_t_header();

int					skip_spaces_before_after_cmd(char *str);
int					skip_numbers(char *str);
int					skip_spaces(char *str);

#endif
