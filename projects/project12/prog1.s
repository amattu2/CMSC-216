# CMSC 216 (Fall 2020)
# Section: 0303 (M/W 8am)
# University ID: 117568813
# Directory ID: amattu
# Author: Alec M.
# Date: December 2nd, 2020

# I pledge on my honor that I have not given or received
# any unauthorized assistance on this assignment.

# Program Tasks:
# - Implement prog1.c as assembly
# - Read two integers from input (base, exponent)
# - Print the result of base^exponent
# - Terminate with the standard MIPS assembly call

# Define global variables
.data
  base:      .word  0
  exponent:  .word  0
  i:         .word  0
  ans:       .word  0

# Main Program
.text
main:
  # Set i = 1
  li $t0, 1
  sw $t0, i

  # Set answer = 1
  li $t0, 1
  sw $t0, ans

  # scanf base
  li $v0, 5
  syscall
  sw $v0, base

  # scanf exponent
  li $v0, 5
  syscall
  sw $v0, exponent

  lw $t0, exponent # $t0 = exponent
  lw $t1, base # $t1 = base
  lw $t2, i # $t2 = i
  lw $t3, ans # $t3 = ans

  # Begin loop
  j loop

loop: bgt $t2, $t0, exit # i > exponent
  # ans *= base
  mul $t3, $t3, $t1

  # Increment index
  add $t2, $t2, 1

  # Store $t3 into ans
  sw $t3, ans

  # Next iteration
  j loop

exit:
  # Print out answer
  li $v0, 1
  lw $a0, ans
  syscall

  # Print newline
  li $v0, 11
  li $a0, 10
  syscall

  # End Program
  li $v0, 10
  syscall
