/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:09:32 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/19 18:55:08 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VISUAL_H
#define	VISUAL_H
#include <ncurses.h>
#include <stdlib.h>


int     cykle(int cykles, int player, char *mem, char *clr);
int     put_on_map(int num, int player, char *mem, char *clr);
int     cursor_on_map(int num, int player, char *mem, char *clr);
int     cykle(int cykles, int player, char *mem, char *clr);

int     position(int num, int *x, int *y);

int     test(char *mem, char *clr);

#endif
