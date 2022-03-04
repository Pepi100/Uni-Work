//parcurere si afisarea unor elemente dintr-un array
.data
	v: .long 10, 20, 30, 40
	n: .long 4
	
	formatPrintf: .asciz "%d "
	strnl: .asciz "\n"

.text

.global main

main:
	lea v, %edi
	movl $0, %ecx
	
et_for:
	cmp %ecx, n
	je et_exit
	
	//altfel
	movl (%edi, %ecx, 4), %eax
	
	pushl %ecx
	//afisare %eax
	pushl %eax
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	incl %ecx
	jmp et_for
	 

et_exit:
	movl $1, %eax
	movl $0, %ebx
	int $0x80
