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

# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"

# include "other.h"
# include "func.h"
# include "op.h"


# include <stdlib.h>
# include <stdio.h>

typedef union	u_types {
	long int			num;
	unsigned char		chr;
	unsigned short		shrt;
}				t_types;

typedef struct	s_functions
{
	char				*name;
	char				arg_types;
	t_types				arg_1;
	t_types				arg_2;
	t_types				arg_3;
	struct s_functions	*next;
}				t_functions;

int					live_func(t_functions *func, int line, char *str);

#endif
