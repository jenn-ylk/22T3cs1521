# week 3 tutorial - reads integers from terminal and stores them in an array + prints these out

N_SIZE = 4

main:
        li      $t0, 0
loop1:
        # read integers from the command line and put them into the array
        bge     $t0, N_SIZE, end_loop1  #scanf("%d", &num)
        li      $v0, 5
        syscall

        mul	$t1, $t0, 4		# numbers[i] = num
        sw      $v0, numbers($t1)
        
        add	$t0, $t0, 1
        
        b loop1
end_loop1:

        # print out the array (incrementing the address)
        li      $t0, 0
        la	$t1, numbers		# load address of numbers into $t1
loop2:
        bge     $t0, N_SIZE, end_loop2

        li      $v0, 1
        lw	$a0, ($t1)		# load word from ($t1) into $a0
        syscall
        li      $v0, 11
        li      $a0, '\n'
        syscall


        add     $t0, $t0, 1
        add     $t1, $t1, 4             # go to next address of the array (numbers++)
        b loop2
end_loop2:

        jr      $ra

        .data
numbers:
        .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
