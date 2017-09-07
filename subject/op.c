/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op    op_tab[17] =
{
	{ name func	, f(argc, argv**)									 coding(decimal==hex),cycles, Description			, need codage octal, ?}
	{"live"		,	1	, {T_DIR}												, 1	,0x01, 10	, "alive"								, 0, 0},
	{"ld"		,	2	, {T_DIR | T_IND, T_REG}								, 2	,0x02, 5	, "load"								, 1, 0},
	{"st"		,	2	, {T_REG, T_IND | T_REG}								, 3	,0x03, 5	, "store"								, 1, 0},
	{"add"		,	3	, {T_REG, T_REG, T_REG}									, 4	,0x04, 10	, "addition"							, 1, 0},
	{"sub"		,	3	, {T_REG, T_REG, T_REG}									, 5	,0x05, 10	, "soustraction"						, 1, 0},
	{"and"		,	3	, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}	, 6	,0x06, 6	, "et (and  r1, r2, r3   r1&r2 -> r3"	, 1, 0},
	{"or"		,	3	, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}	, 7	,0x07, 6	, "ou (or   r1, r2, r3   r1 | r2 -> r3" , 1, 0},
	{"xor"		,	3	, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}	, 8	,0x08, 6	, "ou (xor  r1, r2, r3   r1^r2 -> r3"	, 1, 0},
	{"zjmp"		,	1	, {T_DIR}												, 9	,0x09, 20	, "jump if zero"						, 0, 1},
	{"ldi"		,	3	, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}			, 10,0x0a, 25	, "load index"							, 1, 1},
	{"sti"		,	3	, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}			, 11,0x0b, 25	, "store index"							, 1, 1},
	{"fork"		,	1	, {T_DIR}												, 12,0x0c, 800	, "fork"								, 0, 1},
	{"lld"		,	2	, {T_DIR | T_IND, T_REG}								, 13,0x0d, 10	, "long load"							, 1, 0},
	{"lldi"		,	3	, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}			, 14,0x0e, 50	, "long load index"						, 1, 1},
	{"lfork"	,	1	, {T_DIR}												, 15,0x0f, 1000	, "long fork"							, 0, 1},
	{"aff"		,	1	, {T_REG}												, 16,0x10, 2	, "aff"									, 1, 0},
	{0			,	0	, {0}													, 0	,0x00, 0	, 0										, 0, 0}
};
		