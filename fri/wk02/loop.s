# runs a loop that counts from 24 to 42

main:   # $t0 contains count
        li      $t0, 24         # int x = 24;

loop:
        bge     $t0, 42, end_loop       # if (x >= 42) goto end_loop;

        li      $v0, 1          # printf("%d\n", x);
        move	$a0, $t0
        syscall
        li      $v0, 11
        li      $a0, '\n'
        syscall	
        
        addi	$t0, $t0, 3	# $t0 = $t1 + 0        # x += 3;
        b       loop            # goto loop;

end_loop:

        jr      $ra             # return from main

        .data
prompt_str: