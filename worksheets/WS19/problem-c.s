main:
	# sum = 0
	li $t2, 0
	li $t3, 1

	# Read X
	li $v0, 5
	syscall
	move $t0, $v0

	# Read Y
	li $v0, 5
	syscall
	move $t1, $v0

	# Start loop
	j loop

end:
	li $a0, $t0, 0
	li $v0, 10 # terminate
	syscall

loop:
	ble $t0, $t1, end # x <= y
	add $t2, $t2, $t0 # sum += x
	add $t0, $t0, $t3 # x += 1
	j loop
