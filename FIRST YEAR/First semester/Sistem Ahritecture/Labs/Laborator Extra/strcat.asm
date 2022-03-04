.data
	x: .asciz "am pula "
	y: .asciz "mare"
	aux: .space 100
	
	formatscanf: .asciz "%[^\n]"
	formatprintf: .asciz "%s\n"
	
	
.text

.global main

main:

	movl $x, %eax
	movl %eax, aux
	
	pushl $y
	pushl aux
	call strcat
	popl %ebx
	popl %ebx
	
	pushl %eax
	pushl $formatprintf
	call printf
	popl %ebx
	popl %ebx




etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80
