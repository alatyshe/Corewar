.name "aaaaaaaaa"
.comment "HAHAHAaaa"


	ld	%33554431,r2		# live process 01ffffff
	ld	%4278190080,r3				# name player

	# ld	%33554432,r4	#ld		02 00 00 00	// min 109 byte 1 1 args
	# ld	%66060288,r4	#st		03 00 00 00 // min 109 byte 1 2 args
	# ld	%67108864,r4	#add	04 00 00 00 // min 109 byte 1 3 args
	# ld	%83886080,r4	#sub	05 00 00 00 // min 109 byte 1 3 args
	# ld	%100663296,r4	#and	06 00 00 00 // min 109 byte 1 3 args
	# ld	%117440512,r4	#or		07 00 00 00 // min 109 byte 1 3 args
	ld	%150732800,r4	#xor	08 00 00 00 // min 109 byte 1 3 args
	# ld	%150994944,r4	#zjmp	09 00 00 00 // min 000 byte 1
	# ld	%167772160,r4	#ldi	10 00 00 00 // min 000 byte 1
	# ld	%184549376,r4	#sti	11 00 00 00 // min 000 byte 1
	# ld	%201326592,r4	#fork	12 00 00 00 // work000 byte 0
	# ld	%218103808,r4	#lld	13 00 00 00 // min 000 byte 1
	# ld	%234881024,r4	#lldi	14 00 00 00 // min 000 byte 1
	# ld	%251658240,r4	#lfork	15 00 00 00 // min 000 byte 0
	# ld	%268435456,r4	#aff	16 00 00 00 // min 000 byte 1


	st	r4,57				#cmd  load

	st	r2,60				#live load
	st	r3,59				#name load


	# live	%-1
	# fork %-100

# 02900000
