.name "zork"
.comment "just a basic living prog"
		
a:	live	%4294967295

sadas:	live	%4294967295
		

		zjmp	%-1
l2:		sti	r1,%1,%4294967295
		and	r0,%0,r2

# l2:	ld %4294967295,r1
# 	aff r1