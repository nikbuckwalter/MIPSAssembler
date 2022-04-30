# Spring 2019 Full Assembler
# Test file 8
# Tests:  - pseudos:  move, blt, li, lw
#         - integer data segment
#         - full-line comments
#
# Maximum points:  11.0

.data
val01:  .word    839293
val02:  .word    903923

.text
main:
# Try some pseudo-instructions:
        lw   $t7, val01
        lw   $t8, val02
        li   $t7, 23421
        blt  $t8, $t7, exit
# Try some more:
        li   $t9, -29321
        move $t8, $t9
exit:
        syscall
# That's all...
