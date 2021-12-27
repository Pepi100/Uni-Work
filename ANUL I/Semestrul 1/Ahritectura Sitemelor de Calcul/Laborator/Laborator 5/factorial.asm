.data

n: .long 6
prod: .space 4
	
.text

.global main



fact:
	pushl %ebp
	movl %esp, %ebp
	
	movl 8(%ebp), %eax
	cmp $0, %eax
	je eZero
	
	decl %eax
	
	pushl %eax
	call fact
	popl %ebx
	
	movl 8(%ebp), %eax
	movl prod, %ecx
	mul %ecx
	
	movl %eax, prod
	jmp inchide
	
	
	
eZero:
	movl $1, prod	
	
inchide:
	popl %ebp
	ret


main:

pushl n
call fact
popl %ebx


et_exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80


