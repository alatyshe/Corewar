.name "zork"
.comment "just a basic living prog"
		
live:	live	%4294967295
		live	%4294967295
	zjmp	%:live
l2:	sti	r1,%1,%4294967295
	and	r0,%0,r2

# l2:	ld %4294967295,r1
# 	aff r1
