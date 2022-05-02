# Spring 2019 Milestone 2
# Test file 1
# Tests: - all specified instructions from Milestone 1
#        - integer values in data segment
# Maximum score: 10.0

.data
val01:  .word  32767
val02:  .word  -31
val03:  .word  4324323
val04:  .word  -2343224

.text
        add  $s0, $s1, $s5
        addi $s0, $s1, -1
	and  $s3, $s2, $s3
	andi $v0, $s7, -4096

        nor  $s3, $s1, $s7

        slti  $v0, $s5, -32768
        syscall
