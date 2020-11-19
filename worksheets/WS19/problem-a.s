# Variables
li $t0, 10
li $t1, 1
li $t2, 2

# Main Function
main:
	add $t0, $t0, $t1 # x += 1
	mul $t0, $t0, $t2 # x *= 2

	li $a0, $t0, 0
	syscall # print "buffer"

	li $v0, 10 # terminate
	syscall
