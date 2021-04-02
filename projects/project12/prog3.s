# CMSC 216 (Fall 2020)
# Section: 0303 (M/W 8am)
# University ID: -
# Directory ID: amattu
# Author: Alec M.
# Date: December 3rd, 2020

# I pledge on my honor that I have not given or received
# any unauthorized assistance on this assignment.

# Program Tasks:
# - Implement prog3.c as assembly
# - Implement prog2.s as a recursive function
# - Read two integers from input (number, exponent)
# - Display the sum of the positive divisors including 1 (SOPD)
# - Make use of functions and arguments
# - Terminate with the standard MIPS assembly call

# Define global variables
.data
  number: .word 0
  exponent: .word 0

# Main Program
.text
main:
  # Read integer for base
  li $v0, 5
  syscall

  # Store into base
  sw $v0, number

  # Read integer for exponent
  li $v0, 5
  syscall

  # Store into exponent
  sw $v0, exponent

  # Default return value
  addi $v0, $zero, -1 # ans = -1

  # if exponent < 0 or number < 1, return
  li $t7, 1
  lw $t1, number
  blt $t1, $t7, main_end
  lw $t1, exponent
  blt $s1, $zero, main_end

  # Call sopd with stack
  # Return is in $v0 (convention)
  addiu $sp, $sp, -12
  lw $a0, number
  sw $a0, 12($sp)
  lw $a1, exponent
  sw $a1, 8($sp)
  li $a2, 1
  sw $a2, 4($sp)
  jal sopd
  addiu $sp, $sp, 12

main_end:

  add $a0, $v0, $zero # integer to print
  li $v0, 1
  syscall

  # Newline
  li $v0, 11
  li $a0, 10
  syscall

  # End
  li $v0, 10
  syscall


# power() function
power:
  lw $t0, 8($sp) # base
  lw $t1, 4($sp) # exponent

  li $t3, 1  # ans = 1

  li $t4, 1  # i = 1
  power_loop:
    # if i > exponent
    slt $t5, $t1, $t4
    bne $t5, $zero, power_loop_end

    mult $t3, $t0
    mflo $t3

    addi $t4, $t4, 1  # Increment i
    j power_loop
  power_loop_end:
    add $v0, $t3, $zero
    jr $ra


# SOPD function
sopd:
  # Prologue
  lw $s0, 12($sp) # number
  lw $s1, 8($sp) # exponent
  lw $s2, 4($sp) # i
  addiu $sp, $sp, -8
  sw $ra, 8($sp)
  sw $fp, 4($sp)
  add $fp, $sp, 8

  li $s3, 0  # ans = 0

  # if number < i, return
  blt $s0, $s2, sopd_end

  # num % i
  div $s0, $s2
  mfhi $t7
  bne $t7, $zero, sopd_skip

  # Call power with stack args
  addiu $sp, $sp, -8
  sw $s2, 8($sp)  # Store i/base
  sw $s1, 4($sp)  # Store exponent
  jal power
  addiu $sp, $sp, 8

  # result = ans
  add $s3, $v0, $zero

  sopd_skip:
    # Increment i
    add $s2, $s2, 1

    # Recursively call sopd
    # Store stack
    addiu $sp, $sp, -28
    sw $s3, 28($sp)
    sw $s2, 24($sp)
    sw $s1, 20($sp)
    sw $s0, 16($sp)
    sw $s0, 12($sp) # number
    sw $s1, 8($sp)  # exponent
    sw $s2, 4($sp)  # i
    jal sopd

    # Restore stack
    lw $s3, 28($sp)
    lw $s2, 24($sp)
    lw $s1, 20($sp)
    lw $s0, 16($sp)
    addiu $sp, $sp, 28

    # Add result of sopd
    add $s3, $s3, $v0

  sopd_end:
    add $v0, $s3, $zero

    # Epilogue
    # Restore $RA and pointer
    lw $ra, 8($sp)
    lw $fp, 4($sp)
    add $sp, $sp, 8
    jr $ra
