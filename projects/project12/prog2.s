# CMSC 216 (Fall 2020)
# Section: 0303 (M/W 8am)
# University ID: -
# Directory ID: amattu
# Author: Alec M.
# Date: December 3rd, 2020

# I pledge on my honor that I have not given or received
# any unauthorized assistance on this assignment.

# Program Tasks:
# - Implement prog2.c as assembly
# - Implement prog1.s as a function
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

  # Store in exponent
  sw $v0, exponent

  # Call sopd with stack
  # Return value is in v0 (convention)
  addiu $sp, $sp, -8
  lw $a0, number
  sw $a0, 8($sp)
  lw $a1, exponent
  sw $a1, 4($sp)
  jal sopd
  addiu $sp, $sp, 8

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
  lw $s0, 8($sp) # number
  lw $s1, 4($sp) # exponent
  addiu $sp, $sp, -8
  sw $ra, 8($sp)
  sw $fp, 4($sp)
  add $fp, $sp, 8

  li $s2, -1  # ans = -1

  # if exponent < 0 or number < 1, return
  li $t7, 1
  blt $s0, $t7, sopd_end
  blt $s1, $zero, sopd_end

  li $s2, 0  # ans
  li $s3, 1  # i

  sopd_loop:
    # if i > number, break
    slt $t7, $s0, $s3
    bne $t7, $zero, sopd_loop_end

    # num % i
    div $s0, $s3
    mfhi $t7
    bne $t7, $zero, sopd_skip

    # Call power()
    addiu $sp, $sp, -8
    sw $s3, 8($sp)  # Store i/base
    sw $s1, 4($sp)  # Store exponent
    jal power
    addiu $sp, $sp, 8

    # Return value
    add $s2, $s2, $v0

  sopd_skip:
    addi $s3, $s3, 1  # Increment i
    j sopd_loop

  sopd_loop_end:
  sopd_end:
    add $v0, $s2, $zero

    # Epilogue
    # Restore $RA and pointer
    lw $ra, 8($sp)
    lw $fp, 4($sp)
    add $sp, $sp, 8
    jr $ra
