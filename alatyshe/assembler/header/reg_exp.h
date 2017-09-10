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


typedef struct	s_reg_exp
{
	char				type;
	char				*string;

	char				at_the_start;
	char				at_the_end;

	int					repeat_min;
	int					repeat_max;


	char				*mast_be;
	char				*should_not_be;
	char				*can_be;

	struct s_reg_exp	*next;
}				t_reg_exp;



#endif