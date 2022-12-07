.data
	i: .long 0
	j: .long 0
	valori: .long 0
	indexi: .long 0
	indexj: .long 0
	
	val: .long 0
	
	str: .space 2000
	matrix: .space 1600
	aux: .space 1600
	index: .space 4
	cuv: .space 4
	
	endl: .asciz "\n"
	
	formatScanf: .asciz "%[^\n]"
	formatPrintf: .asciz "%d "
	formatEndl: .asciz "%s"
	delim: .asciz " "
	
.text



.global main

main:
	
	//citire
	
	pushl $str
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx
	
	pushl $delim
	pushl $str
	call strtok
	popl %ebx
	popl %ebx
	
	//scapam de x-ul initial si citim cele 2 dimensiuni
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	pushl %eax
	call atoi
	popl %ebx
	
	movl %eax, i
	
	
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	
	pushl %eax
	call atoi
	popl %ebx
	
	movl %eax, j
	
	
	movl i, %ebx
	mul %ebx
	movl %eax, valori
	
	
	movl $0, index
	
	lea matrix, %edi
	
et_forCitire:
	movl index, %ecx
	
	cmp %ecx, valori
	je continuare
	
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	
	pushl %eax
	call atoi
	popl %ebx
	
	movl index, %ecx
	
	movl %eax, (%edi, %ecx, 4)
	
	
	
	incl index
	jmp et_forCitire
	
	
continuare:
	//citire let
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	//citire valoarea cu care se opereaza
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	
	pushl %eax
	call atoi
	popl %ebx
	
	movl %eax, val
	
	//citire operatie
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	movl %eax, cuv
	
	xorl %ecx, %ecx
	xorl %eax, %eax
	movl cuv, %esi
	
	movb (%esi, %ecx, 1), %al
	
	cmp $97, %al
	je et_add
	cmp $115, %al
	je et_sub
	cmp $109, %al
	je et_mul
	cmp $100, %al
	je et_div
	cmp $114, %al
	je et_rot
	
	
	
et_add:
	
	xorl %ecx, %ecx
	movl %ecx, index
	lea matrix, %esi

forAdd:
	
	movl index, %ecx
	
	movl (%esi, %ecx, 4) , %eax
	add val, %eax
	
	movl %eax, (%esi, %ecx, 4)
	
	incl %ecx
	
	cmp valori, %ecx
	je afisare
	
	
	incl index
	jmp forAdd
	

	
et_sub:
	xorl %ecx, %ecx
	movl %ecx, index
	lea matrix, %esi

forSub:
	
	movl index, %ecx
	
	movl (%esi, %ecx, 4) , %eax
	sub val, %eax
	
	movl %eax, (%esi, %ecx, 4)
	
	incl %ecx
	
	cmp valori, %ecx
	je afisare
	
	
	incl index
	jmp forSub
	
	
	
et_mul:

	xorl %ecx, %ecx
	movl %ecx, index
	lea matrix, %esi

forMul:
	
	movl index, %ecx
	
	movl (%esi, %ecx, 4) , %eax
	movl val, %ebx
	
	xorl %edx, %edx
	imul %ebx
	
	movl %eax, (%esi, %ecx, 4)
	
	incl %ecx
	
	cmp valori, %ecx
	je afisare
	
	
	incl index
	jmp forMul
	
et_div:

	xorl %ecx, %ecx
	movl %ecx, index
	lea matrix, %esi

forDiv:
	
	movl index, %ecx
	
	movl (%esi, %ecx, 4) , %eax
	movl val, %ebx
	
	xorl %edx, %edx
	cdq
	
	idiv %ebx
	
	movl %eax, (%esi, %ecx, 4)
	
	incl %ecx
	
	cmp valori, %ecx
	je afisare
	
	
	incl index
	jmp forDiv
	
et_rot:

	

	xorl %ecx, %ecx
	movl %ecx, index
	lea matrix, %esi
	lea aux, %edi
	
	
	movl $0 ,indexj
	movl $0 ,index
	 
	 
	forj:
	
		movl i, %ebx
		sub $1, %ebx
		movl %ebx, indexi 
		//i=n-1
		
		movl j, %ebx
		cmp indexj, %ebx
		je afisarerot

		
		fori:
			
			xorl %edx, %edx
		
			movl j, %eax
			movl indexi, %ecx
		
			mul %ecx
		//%eax *= %ecx
		
			movl indexj, %ecx
		
			add %ecx, %eax
			movl %eax, %ebx
		//ebx indicele din sursa
			movl index, %ecx
		//ecx indicele din destinatie
			
			movl (%esi, %ebx, 4), %eax
			
			movl index, %ecx
			movl %eax, (%edi, %ecx, 4)
			

			incl index
		
			movl $0, %ebx
			cmp indexi, %ebx
			je iesire
		
			decl indexi
			jmp fori
		
	iesire:
	incl indexj
	jmp forj

	jmp afisarerot
	
	
afisarerot:

	movl i, %eax
	movl j, %ebx
	movl %ebx, i
	movl %eax, j

	lea aux, %esi	
	
	jmp final
	
	
afisare:
	lea matrix, %esi

final:

	movl $0, index
	pushl i
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	pushl j
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	et_for:
	
	movl index, %ecx
	
	//afisare elem de pe pox ecx
	
	movl (%esi, %ecx, 4) , %eax
	pushl %eax
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	//decomentarea acestor linii realizeaza afisarea matricei pe mai multe linii
	//movl index, %ecx
	//incl %ecx
	
	//movl %ecx, %eax
	//movl j, %ebx
	
	//div %ebx
	
	//cmp $0, %edx
	//je endline
	
intoarcere:
	
	movl index, %ecx
	incl %ecx
	
	cmp %ecx, valori
	je et_exit


	incl index
	jmp et_for
	
	
	
endline:
	pushl $endl
	pushl $formatEndl
	call printf
	popl %ebx
	popl %ebx
	jmp intoarcere


et_exit:

	pushl $endl
	pushl $formatEndl
	call printf
	popl %ebx
	popl %ebx
	
	
	
	mov $1, %eax
	xorl %ebx, %ebx
	int $0x80
