.data
	str: .space 1000
	formatscanf: .asciz "%[^\n]"
	formatprintf: .asciz "%d\n"
	
	
	delim: .asciz " "
	
	cuv: .space 4
	x: .long 0
	y: .long 0
	
.text


.global main

main:
	
	
	pushl $str
	pushl $formatscanf
	call scanf
	popl %ebx
	popl %ebx
	
	
	
	pushl $delim
	pushl $str
	call strtok
	popl %ebx
	popl %ebx
	
	movl %eax, cuv
	
	pushl cuv
	call atoi
	popl %ebx
	
	pushl %eax
	
		
	
	
	
et_for:
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je et_exit
	

	movl %eax, cuv
	
	pushl cuv
	call atoi
	popl %ebx
	
	cmp $0, %eax
	je operatie
	
	pushl %eax
	
	
	
	
	
	
	
	
	
	jmp et_for
	
	

operatie:
	movl cuv, %esi
	movl $0, %ecx
	movb (%esi, %ecx, 1), %al
	cmp $109, %al
	je et_mul
	cmp $100, %al
	je et_div
	cmp $115, %al
	je et_sub
	cmp $97, %al
	je et_add
	
	
et_add:
	xorl %edx, %edx
	popl %eax
	popl %ecx
	add %ecx, %eax
	
	pushl %eax
	jmp et_for

et_div:
	xorl %edx, %edx
	popl %ecx
	popl %eax
	div %ecx

	pushl %eax
	jmp et_for

et_mul:
	xorl %edx, %edx
	popl %eax
	popl %ecx
	mul %ecx
	
	pushl %eax
	jmp et_for
	

et_sub:
	xorl %edx, %edx
	popl %ecx
	popl %eax
	sub %ecx, %eax
	
	pushl %eax
	jmp et_for
		
	
	

et_exit:
	
		pushl $formatprintf
		call printf
		popl %ebx
		popl %ebx	
	
	
	mov $1, %eax
	xor %ebx, %ebx
	int $0x80
