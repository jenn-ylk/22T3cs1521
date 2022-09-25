# Print every third number from 24 to 42.

main:
        # for (int x = 24; x < 42; x += 3) {
        #     printf("%d\n", x);
        # }
        li      $t0, 24
loop:
        bge     $t0, 42, end_loop       # if (x >= 42) goto end_loop;

        li      $v0, 1                  # printf("%d\n", x);
        move    $a0, $t0
        syscall
        li      $v0, 11
        li      $a0, '\n'
        syscall

        add	$t0, $t0, 3	        # x += 3	# $t0 = $t1 + $t2

        b loop

end_loop:
        jr      $ra             # return from main

        .data