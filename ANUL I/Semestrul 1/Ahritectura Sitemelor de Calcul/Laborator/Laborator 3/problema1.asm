.data
	a: .long 5
	b: .long 6
	c: .long 3
	str1: .asciz "a este cel mai mic numar\n"
	str2: .asciz "b este cel mai mic numar\n"
	str3: .asciz "c este cel mai mic numar\n"
	
.text

.globl _start

_start:
	mov a, %eax
	mov b, %ebx
	
	cmp %eax, %ebx
	jge p2
	
	
p1:
	mov c, %eax
	cmp %eax, %ebx
	jge cmic
	jmp bmic
	

p2:
	mov c, %ebx
	cmp %eax, %ebx
	jge amic
	jmp cmic



amic:
	mov $4, %eax
	mov $1, %ebx
	mov $str1, %ecx
	mov $25, %edx
	int $0x80
	
	jmp etexit

bmic:
	mov $4, %eax
	mov $1, %ebx
	mov $str2, %ecx
	mov $25, %edx
	int $0x80
	
	jmp etexit

cmic:
	mov $4, %eax
	mov $1, %ebx
	mov $str3, %ecx
	mov $25, %edx
	int $0x80
	
	jmp etexit
	
	
	
	


etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80
