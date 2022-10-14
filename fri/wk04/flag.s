# This program prints out a danish flag, by
# looping through the rows and columns of the flag.
# Each element inside the flag is a single character.
# (i.e., 1 byte).
#
# (Dette program udskriver et dansk flag, ved at
# sløjfe gennem rækker og kolonner i flaget.)
# 

FLAG_ROWS = 6
FLAG_COLS = 12

main:   # row count in $t0, cols in $t1

        li      $t0, 0  # row = 0
loop_row:
        bge     $t0, FLAG_ROWS, loop_row_end

        li      $t1, 0
loop_col:
        bge     $t1, FLAG_COLS, loop_col_end

        #TODO: calculate the memory offset, load the byte and print it
        mul	$t2, $t0, FLAG_COLS
        add     $t2, $t2, $t1
        lb      $a0, flag($t2)

        li      $v0, 11
        syscall
        li      $v0, 11
        li      $a0, ' '
        syscall

        add     $t1, $t1, 1
        b	loop_col			# branch to loop_col
loop_col_end:
        li      $v0, 11
        li      $a0, '\n'
        syscall

        add     $t0, $t0, 1
        b       loop_row
loop_row_end:

        jr      $ra

        .data
flag:
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'