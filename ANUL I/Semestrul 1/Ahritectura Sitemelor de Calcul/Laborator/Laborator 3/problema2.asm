.data
	n: .long 5
	s: .space 4
	v: .long 1, 2, 3, 4, 5

.text

.globl _start

_start:
	
mov $0, %eax #pentru suna
mov $v, %edi #adresa lui v in edi
mov n, %ecx # i-ul din fr


	
etloop:
	mov n, %edx
	sub %ecx, %edx   #edx = n - i
	addl (%edi, %edx, 4), %eax
loop etloop 


etexit:
	mov $1, %eax
	mov $0, %ebx
	int $0x80




