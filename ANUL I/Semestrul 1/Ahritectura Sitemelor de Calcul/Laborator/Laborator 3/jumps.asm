.data
	x: .long 5
	y: .long 8
	str1: .asciz "x < y\n"
	str2: .asciz "x => y\n"
.text

.globl _start

_start:
	mo


etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80
