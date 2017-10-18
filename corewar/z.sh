# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    text.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 17:49:46 by akaplyar          #+#    #+#              #
#    Updated: 2017/10/14 14:46:16 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
if [ -n "$1" ]
then
	i=$1
	shift
	j=$(($# + 2))
	./corewar1 -v $i $* | tail -n +$j > diff.li
	./corewar -v $i $* | tail -n +$j > diff.my
	diff -b diff.my diff.li > text.txt
#	rm diff.my diff.li
	if test -s text.txt
	then
		echo "Shit, check tests dir :("
	else
		echo "Great! No diffs"
		rm -f tests/text.txt
	fi
	exit 0
else
	echo "No args!!!!!"
	exit 0
fi
