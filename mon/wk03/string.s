# week 3 tutorial

main:   # length in $t0, s in $t1

        li	$t0, 0			# length = 0
        la	$t1, string		# load address of var1 into $t1# char *s = &string[0];
loop:
        # TODO: loop through all characters in the array to find the length
        lb	$t2, ($t1)		# load byte from 0($s1) into $t1
        beqz    $t2, end_loop

        add     $t0, $t0, 1
        add     $t1, $t1, 1     # s++

        b	loop			# branch to loop
end_loop:

        move	$a0, $t0		# a = $t1
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        jr      $ra

        .data
string:
        .asciiz "hello there"