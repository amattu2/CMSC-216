.data
  number: .word 0
  exponent: .word 0

.text

main:
  # Read in the first integer for 'base'.
  li $v0, 5
  syscall
  
  # Store the value in 'base'
  sw $v0, number
  
  # Read in the second integer for 'exponent'.
  li $v0, 5
  syscall
  
  # Store the value in 'base'
  sw $v0, exponent
  
  # Store -1 in the result in case of early return
  addi $v0, $zero, -1

  # if exponent < 0 or number < 1, then return early.
  li $t7, 1
  lw $t1, number
  blt $t1, $t7, main_end
  lw $t1, exponent
  blt $s1, $zero, main_end

  # Call 'sopd' by passing the two arguments on the stack. Return value is in 'v0'.
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

  add $a0, $v0, $zero       # $integer to print
  li $v0, 1       
  syscall 
  
  # End program
  li $v0, 10
  syscall
  
      
# Accepts 2 arguments: 'base' and 'exponent'.
# Returns the computed integer value (ignoring overflow).
#
# Arguments are expected to be pushed on the stack.
# Uses `v0` to return output.
power:
  lw $t0, 8($sp) # 'base'
  lw $t1, 4($sp) # 'exponent'
  
  li $t3, 1  # 'ans'
  
  li $t4, 1  # i
  power_loop:
    # If 'i' is greater than 'exponent', break.
    slt $t5, $t1, $t4
    bne $t5, $zero, power_loop_end

    mult $t3, $t0
    mflo $t3
    
    addi $t4, $t4, 1  # Increment i by 1.
    j power_loop
  power_loop_end:
    add $v0, $t3, $zero
    jr $ra    
   
 
# Accepts 3 arguments: 'num', 'n', and 'i'.
# Returns the sum of the n'th powers of all the positive divisers of num.
#
# Arguments are expected to be pushed on the stack.
# Uses `v0` to return output.
sopd:
  # Prologue -- Load params and then save the return address and frame pointer
  lw $s0, 12($sp) # 'number'
  lw $s1, 8($sp) # 'exponent'
  lw $s2, 4($sp) # 'i'
  addiu $sp, $sp, -8
  sw $ra, 8($sp)
  sw $fp, 4($sp)
  add $fp, $sp, 8
  
  li $s3, 0  # 'ans'

  # if 'number' is smaller than 'i', return early.
  blt $s0, $s2, sopd_end

  # `num % i`. The HI bits contain the modulo.
  div $s0, $s2
  mfhi $t7
  bne $t7, $zero, sopd_skip

  # Call 'power' by passing the two arguments on the stack. Return value is in 'v0'.
  addiu $sp, $sp, -8
  sw $s2, 8($sp)  # Store 'i' as 'base'
  sw $s1, 4($sp)  # Store 'exponent' as 'exponent'
  jal power
  addiu $sp, $sp, 8
    
  # Assign the result to 'ans'.
  add $s3, $v0, $zero
  
  sopd_skip:
    #Increment i
    add $s2, $s2, 1
    
    # Recursive call to `sopd`. Make sure to save all of the `s` registers to restore
    # after the function call returns. Return value is in `v0`.
    addiu $sp, $sp, -28
    sw $s3, 28($sp)
    sw $s2, 24($sp)
    sw $s1, 20($sp)
    sw $s0, 16($sp)
    sw $s0, 12($sp) # number
    sw $s1, 8($sp)  # exponent
    sw $s2, 4($sp)  # i
    jal sopd
    lw $s3, 28($sp)
    lw $s2, 24($sp)
    lw $s1, 20($sp)
    lw $s0, 16($sp)
    addiu $sp, $sp, 28
    
    # Append the result into answer.
    add $s3, $s3, $v0
    
  sopd_end:
    add $v0, $s3, $zero
    
    # Epilogue -- Restore the old return address and frame pointer
    lw $ra, 8($sp)
    lw $fp, 4($sp)
    add $sp, $sp, 8
    jr $ra
