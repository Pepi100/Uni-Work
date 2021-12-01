.data

   helloWorld: .asciz "Hello, World!\n"

.text

.globl _start

_start:

 
   
   mov $helloWorld, %ecx
   
   
   mov $4, %eax
   mov $1, %ebx
   mov $15, %edx
   
   int $0x80
   
   #finalizare
   
   mov $1, %eax
   mov $0, %ebx
   int $0x80
