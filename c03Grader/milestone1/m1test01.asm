# Spring 2022 Assembler Milestone 1
# m1test01.asm
#
# Test R-format:  add, nor, and
# Maximum score:  6.0

.text
main:
        add   $s0, $s1, $s2
        add   $s3, $s4, $s5
        add   $s6, $s7, $v0

        nor   $v1, $s3, $s5
        nor   $s1, $s6, $v0
        nor   $s3, $s5, $s0

	and   $s0, $v1, $s3
	and   $s1, $v0, $s6
	and   $s2, $s4, $s5
