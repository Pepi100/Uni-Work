.data
	
	
	cuv: .space 10
	variabile: .space 112
	str: .space 1000
	
	formatscanf: .asciz "%[^\n]"
	formatprintf: .asciz "%d\n"
	delim: .asciz " "
	
	
	
	
.text


.global main

main:
	
	
	pushl $0
	
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
	
	cmp $0, %eax
	je pushcuv
	jmp pushcif
	


pushcif:
	pushl %eax
	jmp et_for	

	
pushcuv:
	pushl cuv
	jmp et_for		
	
	
	
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
	je opersauvar
	
variabila:	
	pushl %eax
	
		
	jmp et_for
	
	
	
opersauvar:
	
	pushl cuv
	call strlen
	popl %ebx
	
	cmp $1, %eax
	je et_var
	jmp operatie
	
et_var:
	xorl %ebx, %ebx
	movl cuv, %esi
	movl $0, %ecx
	movb (%esi, %ecx, 1), %bl
	//bl = 'x'
	sub $97, %ebx
	
	movl $variabile, %esi
	movl (%esi, %ebx, 4), %eax
	cmp $0, %eax
	je punere
	jmp inlocuire
	
punere:
	movl cuv, %eax
	jmp variabila

inlocuire:
	movl (%esi, %ebx, 4), %eax
	jmp variabila
	
	

	
	

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
	cmp $108, %al
	je et_let
	
et_let:
	popl %eax
	popl %esi
	xorl %ebx, %ebx
	xorl %ecx, %ecx
	movb (%esi, %ecx, 1), %bl
	subb $97, %bl
	
	movl $variabile, %esi
	
	movl %eax, (%esi, %ebx, 4) 
	
	
	jmp et_for

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
