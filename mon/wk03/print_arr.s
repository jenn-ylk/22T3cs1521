# week 3 tutorial

N_SIZE = 10

main:   # counter in $t0, array address in $t1

        li      $t0, 0  # i = 0
loop:
        
        # TODO: read the value from the array and print it (using lw)

        
end_loop:

        jr      $ra

        .data
numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9