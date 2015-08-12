1:	st X+, r21
.globl __memset_x
__memset_x:
	subi r23, 1
	brne 1b
	ret

