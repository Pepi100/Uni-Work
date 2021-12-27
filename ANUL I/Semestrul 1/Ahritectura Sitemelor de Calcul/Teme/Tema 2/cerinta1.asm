.data

	vInitial: .space 400
	rezultat: .space 400
	aparitii: .space 150
	ultima: .space 150
	str: .space 300
	
	n: .long 0
	l: .long 0
	m: .long 0
	k: .long 0
	aux: .long 0
	i: .long 0
	retinut: .long 0

	
	formatScanf: .asciz "%[^\n]"
	formatAfisare: .asciz "%d "
	formatTest: .asciz "%d\n"
	formatNewline: .asciz "\n"
	delim: .asciz " "
	
.text


	

.global main

afisare:
	 
	 pushl %ebp
	 movl %esp, %ebp
	 
	 xorl %ecx, %ecx
	 lea rezultat, %esi
	 
	 for_afisare:
	 	cmp %ecx, l
	 	je exit_afisare
	 	
	 	movl (%esi, %ecx, 4), %eax
	 	
	 	pushl %ecx
	 	
	 	pushl %eax
		push $formatAfisare
		call printf
		popl %ebx	
		popl %ebx
	 	
	 	popl %ecx
	 	
	 	incl %ecx
	 	jmp for_afisare

	exit_afisare:
		
		push $formatNewline
		call printf
		popl %ebx
	
	
		popl %ebp
		ret
		
		
btk:
	pushl %ebp
	movl %esp, %ebp
	
	//call afisare
	
	
	
	movl 8(%ebp), %eax
	movl %eax, k
	

	
	movl k, %eax
	cmp %eax, l
	je jmp_afisare
	
	//verificam daca are valoare initiala
	
	movl k, %ecx
	lea vInitial, %esi
	
	movl (%esi, %ecx, 4), %eax
	movl %eax, aux
	
	cmp $0, %eax
	je nu_are_val
	
	jmp are_val
	
	are_val:
	
		
		
		lea ultima, %esi
		movl aux, %ecx
		movl (%esi, %ecx, 4), %ebx
		movl k, %eax
	
		sub %ebx, %eax
		
		
		
		cmp m, %eax
		ja are_distanta
		jmp inchide
		
		are_distanta:
		
		
			lea aparitii, %esi
			movl aux, %ecx
			
			movl (%esi, %ecx, 4), %eax
			

			
			cmp $3, %eax
			jb e_bun
			
			jmp inchide
			
			e_bun:
			
				
				lea aparitii, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				add $1, %eax
				movl %eax, (%esi, %ecx, 4) 
				
				lea ultima, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				movl %eax, retinut
				
				lea ultima, %esi
				movl aux, %ecx
				movl k, %eax
				movl %eax, (%esi, %ecx, 4)
				
				movl k, %ecx
				lea rezultat, %esi
				movl aux, %eax
				movl %eax, (%esi, %ecx, 4)
				
				movl k, %eax
				addl $1, %eax
				
				pushl retinut
				pushl aux
				
				pushl %eax
				call btk
				popl %ebx
				
				popl aux
				popl retinut
				
				subl $1, k
				
				lea aparitii, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				subl $1, %eax
				movl %eax, (%esi, %ecx, 4)
				
				lea ultima, %esi
				movl aux, %ecx
				movl retinut, %eax
				movl %eax, (%esi, %ecx, 4)
				
				jmp inchide
				
				
				
			
			
			
		
	
	nu_are_val:
	
			
	
	
		movl $1, %eax
		movl %eax, aux
		
		et_for:
			
			

		
			movl aux, %eax
			cmp n, %eax
			ja inchide
			
		////
		lea ultima, %esi
		movl aux, %ecx
		movl (%esi, %ecx, 4), %ebx
		movl k, %eax
	
		sub %ebx, %eax
	
		cmp m, %eax
		ja are_distanta2
		jmp next
		
		
		are_distanta2:
		
			lea aparitii, %esi
			movl aux, %ecx
			
			movl (%esi, %ecx, 4), %eax
			
			cmp $3, %eax
			jb e_bun2
			
			jmp next
			
			e_bun2:
				
				lea aparitii, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				add $1, %eax
				movl %eax, (%esi, %ecx, 4) 
				
				lea ultima, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				movl %eax, retinut
				
				lea ultima, %esi
				movl aux, %ecx
				movl k, %eax
				movl %eax, (%esi, %ecx, 4)
				
				movl k, %ecx
				lea rezultat, %esi
				movl aux, %eax
				movl %eax, (%esi, %ecx, 4)
				
				movl k, %eax
				addl $1, %eax
				
				pushl retinut
				pushl aux
				
				pushl %eax
				call btk
				popl %ebx
				
				popl aux
				popl retinut
				
				subl $1, k
				
				lea aparitii, %esi
				movl aux, %ecx
				movl (%esi, %ecx, 4), %eax
				subl $1, %eax
				movl %eax, (%esi, %ecx, 4)
				
				lea ultima, %esi
				movl aux, %ecx
				movl retinut, %eax
				movl %eax, (%esi, %ecx, 4)
		
		
			next:
			
			movl aux, %eax
			addl $1, %eax
			movl %eax, aux
			
			jmp et_for
	
	
	
	jmp_afisare:
		call afisare
		jmp et_exit
		
	inchide:
		popl %ebp
		ret
	



citire:
	pushl %ebp
	movl %esp, %ebp
	
	
	
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
	
	pushl %eax
	call atoi
	popl %ebx
	//n
	movl %eax, n
	
	
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	pushl %eax
	call atoi
	popl %ebx
	//m
	movl %eax, m
	
	movl n, %eax
	movl $3, %ecx
	mul %ecx
	movl %eax, l
	
	lea vInitial, %esi
	xorl %ecx, %ecx
	
	
	for_citire:
		
		cmp %ecx, l
		je final_citire
	
		pushl %ecx
		
		pushl $delim
		pushl $0
		call strtok
		popl %ebx
		popl %ebx
	
	
		pushl %eax
		call atoi
		popl %ebx
		
		popl %ecx
		
		movl %eax, (%esi, %ecx, 4)
		
		incl %ecx
		jmp for_citire
		
	
	
	final_citire:

		pushl $0
		call btk
		popl %ebx
	
		popl %ebp
		ret

main:

//setam vectorul ultima la -30

lea ultima, %esi
xorl %ecx, %ecx

for_ultima:
	cmp $30, %ecx
	je continuare_for_ultima
	
	movl $-30, (%esi, %ecx, 4)
	
	incl %ecx
	jmp for_ultima
	
	
	
	
continuare_for_ultima:






call citire
	






et_exitrau:
	pushl $-1
	pushl $formatTest
	call printf
	popl %ebx
	popl %ebx
	

et_exit:

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
