# CMSC 216 (Fall 2020)
# Section: 0303 (M/W 8am)
# University ID: 117568813
# Directory ID: amattu
# Author: Alec M.
# Date: December 2nd, 2020

# I pledge on my honor that I have not given or received
# any unauthorized assistance on this assignment.

# Program Tasks:
# - Implement prog2.c as assembly
# - Implement prog1.s as a function
# - Read two integers from input (number, exponent)
# - Display the sum of the positive divisors including 1 (SOPD)
# - Make use of functions and arguments
# - Terminate with the standard MIPS assembly call

.data
  number:    .word  0
  exponent:  .word  0
  result:    .word  0

.text
main: li $sp, 0x7ffffffc  # set up stack ptr
  # Set number = 0
  li $t0, 0
  sw $t0, number

  # Set exponent = 0
  li $t0, 0
  sw $t0, exponent

  # Set result = 0
  li $t0, 0
  sw $t0, result

  # scanf number
  li $v0, 5
  syscall
  sw $v0, number

  # scanf exponent
  li $v0, 5
  syscall
  sw $v0, exponent

  # Push number to the stack
  #lw $t0, number
  #sw $t0, ($sp)
  #sub $sp, $sp, 4
  lw $a0, number

  # Push exponent to the stack
  #lw $t0, exponent
  #sw $t0, 4($sp)
  #sub $sp, $sp, 4
  lw $a1, exponent

  # Jump to SOPD
  jal sopd

  # Pop arguments
  add $sp, $sp, 8

  # Store SOPD result
  move $t0, $v0
  sw $t0, result

  # Print out result
  li $v0, 1
  lw $a0, result
  syscall

  # Print newline
  li $v0, 11
  li $a0, 10
  syscall

  # End Program
  li $v0, 10
  syscall

power:
  # Prologue
  sub $sp, $sp, 8 # Setup stack pointer
  sw $ra, 8($sp) # Save return address
  sw $fp, 4($sp)
  add $fp, $sp, 8 # New pointer

  # copy from f
  lw $t0, 8($fp)      # get arg. (value of i) in caller's frame
  mul $t0, $t0, 10     # compute i * 10
  move $v0, $t0
  # / copy from f

  # Epilogue
  lw $ra, 8($sp)      # load ret addr from stack
  lw $fp, 4($sp)      # restore old frame ptr from stack
  add $sp, $sp, 8      # reset stack ptr
  jr $ra              # ret to caller using saved ret addr

sopd:
  sub $sp, $sp, 8 # Setup stack pointer
  sw $ra, 8($sp) # Save return address
  sw $fp, 4($sp)
  add $fp, $sp, 8 # New pointer

  # int i = 0
  li $v0, 1

  # Ans = -1
  li $v1, -1

  # Read argument 1
  move $t0, $a0

  # Read argument 2
  move $t1, $a1

  # debug
  li $v0, 1
  move $a0, $t0
  syscall
  li $v0, 11
  li $a0, 10
  syscall
  li $v0, 1
  move $a0, $t1
  syscall
  li $v0, 11
  li $a0, 10
  syscall
  li $v0, 10
  syscall

  # Epilogue
  move    $v0, $t0         # copy ret value to $v0 before exiting
  lw      $ra, 16($sp)      # load ret addr from stack
  lw      $fp, 12($sp)      # restore old frame ptr from stack
  add     $sp, $sp, 16      # reset stack ptr
  jr      $ra
