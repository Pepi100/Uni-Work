


.data
	formatPrintf: .asciz "Numarul %d\n"
	x: .long 5


.text

.global main

main:
	
	pushl x
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx

et_exit:
	movl $1, %eax  
	movl $0, %ebx
	int $0x80


