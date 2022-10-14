# week 3 tutorial

N_SIZE = 4

main:
        li      $t0, 0
loop1:
        bge     $t0, N_SIZE, end_loop1
        # TODO: read integers from the command line and put them into the array
        li      $v0, 5
        syscall

        mul     $t1, $t0, 4
        sw	$v0, numbers($t1)		

        add	$t0, $t0, 1

        b       loop1
end_loop1:

        # print out the array
        li      $t0, 0
loop2:
        bge     $t0, N_SIZE, end_loop2

        mul     $t1, $t0, 4
        lw      $a0, numbers($t1)
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        add	$t0, $t0, 1

        b loop2
end_loop2:

        jr      $ra

        .data
numbers:
        .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0