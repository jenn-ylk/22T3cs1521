
max:
        # $s0 - first_element
        # $v0 - max_so_far

        # prologue section before code, 
        # add elements to the stack that need to be used
        begin
        push    $ra
        push    $s0

        lw      $s0, ($a0)      # first_element = array[0]
        bne	$a1, 1, recursive	# if $s0 != 1 goto recursive
base: 
        move    $v0, $s0
        b       max_return

recursive:
        add     $a0, $a0, 4
        add     $a1, $a1, -1
        jal     max

        # return from function
        # if (first_element > max_so_far) {
        ble	$s0, $v0, max_return
        move    $v0, $s0        #    max_so_far = first_element;

max_return:
        # epilogue section - pop elements from the stack
        pop     $s0
        pop     $ra
        end				# move frame pointer back
        jr      $ra

main:

        addi    $sp, $sp, -4    # create stack frame
        sw      $ra, 0($sp)     # save return address for after the function call

        la      $a0, array
        li      $a1, 10
        jal     max             # call max(array, 10)

        move    $a0, $v0        # printf ("%d")
        li      $v0, 1
        syscall

        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall

                                # clean up stack frame
        lw      $ra, 0($sp)     # restore $ra
        addi    $sp, $sp, 4     # restore sp

        li      $v0, 0          # return 0
        jr      $ra


.data
array:
    .word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1