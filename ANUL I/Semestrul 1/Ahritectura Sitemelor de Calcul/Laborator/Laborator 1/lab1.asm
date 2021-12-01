.data
  
  n: .word 5
   
.text
.globl _start

_start:

   mov n, %eax
   
   and $1, %eax
   
   
   #acum afisarea
   
   mov %eax, %ecx
   
   
   mov $4, %eax
   mov $1, %ebx
   
   int $0x80
   
   #finalizare
   
   mov $1, %eax
   mov $0, %ebx
   int $0x80
