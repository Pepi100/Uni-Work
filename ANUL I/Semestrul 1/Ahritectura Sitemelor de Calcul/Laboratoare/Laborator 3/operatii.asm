.data
	x: .long 30
	y: .long 7
	prod: .space 4
	cat: .space 4
	rest: .space 4
	
	
.text

.globl _start

_start:
	mov x, %eax
	mov y, %ebx
	
	mul %ebx
	// eax = eax * ebx ( x * y)
	
	mov %eax, prod
	
	
	mov x, %eax
	div %ebx
	
	mov %eax, cat
	mov %edx, rest
	
	
	
	
	


etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80
