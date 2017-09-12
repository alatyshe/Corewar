/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLACK		"\x1b[37m"
# define RESET		"\x1b[0m"

# define SAME		0

# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"

# include <stdlib.h>
# include <stdio.h>

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

typedef struct	s_header
{
	char				*file_name;
	unsigned int		magic;
	char 				*prog_name;
	// char 				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int 		prog_size;
	// char 				comment[COMMENT_LENGTH + 1];
	char 				*prog_comment;
	char				error;
	t_label				*labels;
}				t_header;

# include "asm.h"
# include "op.h"
# include "func.h"
# include "other.h"
# include "validation.h"

#endif
