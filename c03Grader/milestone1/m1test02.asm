# Spring 2022 Assembler Milestone 1
# m1test02.asm
#
# Test I-format:  addi, slti, andi
# Maximum score:  6.0

.text
main:
        addi  $s0, $s1, 63
        addi  $s3, $s4, -63
        addi  $s6, $s7, 4096

        andi  $s1, $s7, 122
        andi  $s6, $s4, -121
        andi  $s3, $s1, 8192

        slti  $v1, $s3, -4096
        slti  $s1, $s6, 13456
        slti  $s3, $s5, -13456
