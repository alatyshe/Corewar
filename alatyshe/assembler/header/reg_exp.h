/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_exp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REG_EXP_H
# define REG_EXP_H

# include "other.h"
# include "func.h"
# include "op.h"
# include "asm.h"
# include "reg_exp.h"

typedef struct	s_exp
{
	char				at_the_start;
	char				at_the_end;
	char				string;
	int					counter;
	struct	s_exp 		*next;	
}				t_exp;

typedef struct	s_reg_exp
{
	char				type;
	char 				*flags;
	char				*string;
	t_exp				*expression;

	struct s_reg_exp	*next;
}				t_reg_exp;



#endif