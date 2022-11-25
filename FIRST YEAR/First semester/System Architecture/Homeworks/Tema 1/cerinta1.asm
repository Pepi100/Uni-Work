.data


	sirb16: .space 102
	sirb2: .space 402
	sirrez: .space 402
	formatscanf: .asciz "%s"
	formatprintf: .asciz "%s "
	formatnewline: .asciz "\n"
	
	div: .asciz "div"
	add: .asciz "add"
	mul: .asciz "mul"
	sub: .asciz "sub"
	let: .asciz "let"
	
	nrpozprint: .asciz "%d "
	nrnegprint: .asciz "-%d "
	variabila: .space 2
	
	nrneg: .long 0
	
	
	indexsirb2: .long 0
	indexsirrez: .long 0
	
.text


.global main

main:

	
	pushl $sirb16
	pushl $formatscanf
	call scanf
	popl %ebx
	popl %ebx

	mov $sirb16, %edi
	mov $sirb2, %esi
	xorl %ecx, %ecx
	
et_for:
	movb (%edi, %ecx, 1), %al
	
	
	
	cmp $0, %al
	je et_interpretare
	
	cmp $48, %al
	je et_cifra0
	
	cmp $49, %al
	je et_cifra1
	
	cmp $50, %al
	je et_cifra2
	
	cmp $51, %al
	je et_cifra3
	
	cmp $52, %al
	je et_cifra4
	
	cmp $53, %al
	je et_cifra5
	
	cmp $54, %al
	je et_cifra6
	
	cmp $55, %al
	je et_cifra7
	
	cmp $56, %al
	je et_cifra8
	
	cmp $57, %al
	je et_cifra9
	
	cmp $65, %al
	je et_cifraa
	
	cmp $66, %al
	je et_cifrab
	
	cmp $67, %al
	je et_cifrac
	
	cmp $68, %al
	je et_cifrad
	
	cmp $69, %al
	je et_cifrae
	
	cmp $70, %al
	je et_cifraf
	
continuare:
	incl %ecx
	jmp et_for
	
	
	
et_cifra0:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra1:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra2:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra3:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra4:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra5:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra6:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare


et_cifra7:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra8:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifra9:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifraa:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare
	
et_cifrab:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifrac:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifrad:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifrae:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_cifraf:
	pushl %ecx
	movl indexsirb2, %ecx
	
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movb $49, (%esi, %ecx, 1)
	incl %ecx
	movl %ecx, indexsirb2
	
	popl %ecx
	jmp continuare

et_interpretare:
	xorl %ecx, %ecx
	movl $sirb2, %esi
	movl $sirrez, %edi
	movl %ecx, indexsirb2
	
	
et_fori:
	
	movb (%esi, %ecx, 1), %al
	
	cmp $0, %al 
	je et_exit
	
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_operatie
	
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_variabila
	jmp et_numar
	
	
	
et_continuarei:
	
	movl $12, %ebx
	add %ebx, indexsirb2
	movl indexsirb2, %ecx	
	
	jmp et_fori
	
	

et_numar:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_nrneg
	jmp et_nrpoz
	
et_nrneg:
	pushl %ecx
	mov $1, %ecx
	mov %ecx, nrneg
	popl %ecx
	
	
et_nrpoz:
	xorl %ebx, %ebx
	
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add128
rep128:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add64
rep64:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add32
rep32:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add16
rep16:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add8
rep8:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add4
rep4:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add2
rep2:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je add1
rep1:
	
	push %ecx
	mov nrneg, %ecx
	cmp $1, %ecx
	je afisneg
	jmp afispoz
	
afispoz:
	popl %ecx	
	push %ebx
	push $nrpozprint
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	jmp et_continuarei

afisneg:
	popl %ecx	
	push %ebx
	push $nrnegprint
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	mov $0, %ecx
	mov %ecx, nrneg
	
	jmp et_continuarei
	
	
	
add128:
	add $128, %ebx
	jmp rep128
add64:
	add $64, %ebx
	jmp rep64
add32:
	add $32, %ebx
	jmp rep32
add16:
	add $16, %ebx
	jmp rep16
add8:
	add $8, %ebx
	jmp rep8
add4:
	add $4, %ebx
	jmp rep4
add2:
	add $2, %ebx
	jmp rep2
add1:
	add $1, %ebx
	jmp rep1


		
	

et_variabila:
	incl %ecx
	xorl %ebx, %ebx
	
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd128
vrep128:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd64
vrep64:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd32
vrep32:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd16
vrep16:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd8
vrep8:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd4
vrep4:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd2
vrep2:
	incl %ecx 
	movb (%esi, %ecx, 1), %al
	cmp $49, %al
	je vadd1
vrep1:
	pushl %ecx
	movl $0, %ecx
	mov $variabila, %edi

	movb %bl, (%edi, %ecx, 1)
	incl %ecx
	//movb $0, (%edi, %ecx, 1)
	popl %ecx
	
	
	push %edi
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx

	jmp et_continuarei
	
vadd128:
	add $128, %ebx
	jmp vrep128
vadd64:
	add $64, %ebx
	jmp vrep64
vadd32:
	add $32, %ebx
	jmp vrep32
vadd16:
	add $16, %ebx
	jmp vrep16
vadd8:
	add $8, %ebx
	jmp vrep8
vadd4:
	add $4, %ebx
	jmp vrep4
vadd2:
	add $2, %ebx
	jmp vrep2
vadd1:
	add $1, %ebx
	jmp vrep1

	

	
	
et_operatie:
	add $8, %ecx 
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al 
	je et_div
	
	incl %ecx
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_mulsub
	
	incl %ecx
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_add
	
	jmp et_let
	
	jmp et_continuarei
	
	
et_mulsub:
	incl %ecx
	movb (%esi, %ecx, 1), %al
	
	cmp $49, %al
	je et_mul
	jmp et_sub
	
	
et_mul:
	push $mul
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	
	jmp et_continuarei

et_sub:
	push $sub
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	
	jmp et_continuarei
	
et_add:
	push $add
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	
	jmp et_continuarei

et_div:
	
	push $div
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	
	jmp et_continuarei
	
et_let:
	push $let
	push $formatprintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	
	jmp et_continuarei
	
	
	



et_exit:
	push $formatnewline
	call printf
	popl %ebx

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
