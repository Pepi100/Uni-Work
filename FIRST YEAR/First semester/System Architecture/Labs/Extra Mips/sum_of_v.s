.data # data section

v:.word 2, 1, 3, 2, 3  # vectorul
n:.word 5 
i: .word 0
sum: .word 0


.text # text section

.globl main # imi dadea eroare fara .globl

main:

la	$t0, v 		#adresa lui v in t0

lw	$t2, i            #i pentru parcurgere
lw	$t3, sum          # suma in t3


intrare:



lw $t1,n
lw $t2,i

#verificam daca n este mai mare ca i
bge   $t2, $t1,  iesire

#daca nu este, continuam loopul

# punem in t4 pe v[i]
lw $t4, ($t0)

#sum = sum + t4
lw $t3,sum
addu $t3, $t3, $t4
sw $t3,sum

# crestem adresa din t0 cu 4 octeti, nu am inteles de ce era inmultire cu 4
# facem asta aici, ca la pasul urmator, t0 sa fie v[i]
addiu	$t0, $t0, 4


# i++ 
lw $t2,i  #iau valoarea lui i
addiu $t2, $t2, 1 #o incrementez
sw $t2,i  # o pun inapoi, cam astia 3 pasi sunt ordinea de lucru generala cand lucrez cu date declarate in .data

j intrare #loopuim


iesire:


#afisam suma din a

addu	$a0, $0, $t3
li	  $v0, 1
syscall


exit:
li	$v0, 10
syscall