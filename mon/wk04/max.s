
max:
        # prologue section before code
        begin
        push	$ra			# push $ra to the stack
        push    $s0

        lw      $s0, ($a0)              # int first_element = array[0];
        
        bne     $a1, 1, recurse         # if length != 1, recursive case
base:
        move    $v0, $s0   
        b       max_return    
recurse:
        addi    $a0, $a0, 4             # int max_so_far = max(&array[1], length - 1);
        addi    $a1, $a1, -1
        jal     max

        # $v0 contains max_so_far
        bge     $v0, $s0, max_return    # if max_so_far >= first_element
        move    $v0, $s0

max_return:
        # epilogue section and placing return value in $v0

        pop	$s0			# pop from the stack into $s0
        pop     $ra                     # puts the proper return address from the caller into $ra
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