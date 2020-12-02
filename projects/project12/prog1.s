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
   base:  .word  0
   exponent:  .word  0
   i:  .word  0
   ans:  .word  0


# Main Program
.text
main:
  # Set i = 1
  li $t0, 1
  sw $t0, i

  # Get integer base
  li $v0, 5
  syscall
  # Move base from $v0 to $t0
  move $t0, $v0
  # Move base from $t0 to base
  sw $t0, base

  # Get integer exponent
  li $v0, 5
  syscall
  # Move exponent from $v0 to $t0
  move $t0, $v0
  # Move exponent from $t0 to exponent
  sw $t0, exponent

  # Begin loop
  j loop

loop:
  # Load global variables
  lw $t0, exponent # exponent
  lw $t1, base # base
  lw $t2, i # index
  lw $t3, ans # answer

  # if i > exponent
  bgt $t2, $t0, exit

  # ans *= base
  mul $t3, $t3, $t1

  # Next iteration
  j loop

exit:
  # Print out answer
  lw $t0, ans
  move $a0, $t0
  syscall

  # End Program
  li $v0, 10
  syscall
