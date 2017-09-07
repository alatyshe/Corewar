# define CHAR_BIT	8
# define CHAR_MIN	–128
# define CHAR_MAX	127
# define UCHAR_MAX	255
# define SHRT_MIN	–32768
# define SHRT_MAX	32767
# define USHRT_MAX	65535
# define INT_MIN	–2147483648
# define INT_MAX	2147483647
# define UINT_MAX	4294967295
# define _I64_MIN	-9223372036854775808
# define _I64_MAX	9223372036854775807
# define _UI64_MAX	18446744073709551615
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	live(1) - вывод сообщения, что процесс "жив" (в 1 аргументе указывается номер игрока)

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

=====================================================================
## code
live:	live	%4294967295
## Output
01ff ffff ff
=====================================================================

=====================================================================
## code	live gives 4 bytes for argv
live:	live	%1
## Output
0100 0000 01
=====================================================================

=====================================================================
## code	live gives 4 bytes for argv
live:	live	%4294967295
	zjmp	%:live
## Output 
01ff ffff ff
09 fffb

#LIKE/////////////////////////////////////////////////////////////////
## ffff ffff == 4294967295(max for u_int)
01 ffff ffff	#live with %4294967295
09 fffb			#zjmp 65531
=====================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%0
	zjmp	%:live
## Output 
01ff ffff ff01 0000 0000 09ff f6

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 0000 0000	#live
09 fff6			#zjmp 65526
=====================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%4294967295
		live	%4294967295
	zjmp	%:live
## Output 
01ff ffff ff01 ffff ffff 01ff ffff ff09 fff1

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
09 fff1			#zjmp 65521
=====================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
	zjmp	%:live
## Output
01ff ffff ff01 ffff ffff 01ff ffff ff01
ffff ffff 09ff ec

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
09 ffec			#zjmp 65516
======================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
	zjmp	%:live
## Output
01ff ffff ff01 ffff ffff 01ff ffff ff01
ffff ffff 01ff ffff ff09 ffe7

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
09 ffe7			#zjmp 65511
======================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
	zjmp	%:live
## Output
01ff ffff ff01 ffff ffff 01ff ffff ff01
ffff ffff 01ff ffff ff01 ffff ffff 09ff
e2

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
09 ffe2			#zjmp 65506
======================================================================

=====================================================================
## code	live gives 4 bytes for argv
## code	zjmp gives 2 bytes for argv
live:	live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
		live	%4294967295
	zjmp	%:live
## Output
01ff ffff ff01 ffff ffff 01ff ffff ff01
ffff ffff 01ff ffff ff01 ffff ffff 01ff
ffff ff09 ffdd 

#LIKE/////////////////////////////////////////////////////////////////
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
01 ffff ffff	#live
09 ffdd			#zjmp 65501
======================================================================

Как я понял, это означает, что лейбл "live:" хранит позицию каретки после исполнения всех функций внутри лейбла,
и как результат пихает это в zjmp.