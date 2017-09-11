/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# define SYNTAX_ERROR	-1
# define LEXICAL_ERROR	–2
# define INVALID_PARR	-3

# include "other.h"
# include "func.h"
# include "op.h"
# include "asm.h"

typedef struct	s_label
{
	char				*label_name;
	int					label_size;
	struct s_function	*functions;
	struct s_label		*next;
}				t_label;

typedef struct	s_function
{
	char				*name;
	char				func_in_hex;
	char				arg_types;
	union u_arg			*arg_1;
	union u_arg			*arg_2;
	union u_arg			*arg_3;
	struct s_function	*next_func;
}				t_function;

typedef union	u_arg {
	long int			num;
	short				shrt;
	unsigned char		chr;
}				t_arg;


int					live_func(t_function *func, int line, char *str);

#endif
