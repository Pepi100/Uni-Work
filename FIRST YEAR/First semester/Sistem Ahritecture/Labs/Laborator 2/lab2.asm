.data

s: .space 12

.text

.globl _start

_start:

	mov $3, %eax
	mov $2, %ebx
	mov $s, %ecx
	mov $12, %edx
	
	int $0x80
	
	
	#afisare
	
	mov $4, %eax
	mov $1, %ebx
	mov $s, %ecx
	mov $20, %edx
	
	int $0x80
	
	
	mov $1, %eax
	mov $0, %ebx
	int $0x80
	
	
