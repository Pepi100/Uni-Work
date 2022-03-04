//suma a doua numere

.data
	x: .long 5
	y: .long 10
	z: .space 4
	
	formatPrintf: .asciz "%d\n"
	
	

.text

.global main


suma:
	//%esp: (adr intoarcere) x y 

	//aplic conventiile
	// 1. punem %ebp pe stiva si il facem pointer in cadrul de apel
	pushl %ebp
	//%esp: ebp vechi, adresa intoarcere, x, y
	movl %esp, %ebp
	//%esp si %ebp: ebp vechi, adresa intoarcere, x, y
	
	movl 8(%ebp), %eax
	movl 12(%ebp), %ecx
	
	// ecx e y, eax e x
	addl %ecx, %eax
	
	//acum eax contine rezultatul
	
	//urmeaza sa fac o restaurare a cadrului de apel
	popl %ebp
	
	ret
	

main:
//apelez suma(x, y)

	pushl y
	pushl x
	call suma
	popl %ebx
	popl %ebx
	
	movl %eax, z
	
	//afisez pe %eax 
	
	pushl z
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx


et_exit:
	movl $1, %eax
	movl $0, %ebx
	int $0x80
