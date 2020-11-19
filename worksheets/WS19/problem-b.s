main:
	# Read X
	li $v0, 5
	syscall
	move $t0, $v0

	# Read Y
	li $v0, 5
	syscall
	move $t1, $v0

	# x > y
	bgt $t0, $t1, greater # true
	blt $t0, $t1, lesser # false

	li $v0, 10 # terminate
	syscall

greater:
	li $a0, $t0, 0 # x
	syscall

lesser:
	li $a0, $t1, 0 # y
	syscall
