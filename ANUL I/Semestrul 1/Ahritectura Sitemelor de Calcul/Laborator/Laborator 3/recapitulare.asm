.data
	sir: .asciz "Hello\n"
	
.text

.globl _start

_start:
	mov $4, %eax
	mov $1, %ebx
	mov $sir, %ecx
	mov $10, %edx
	int $0x80

etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80
