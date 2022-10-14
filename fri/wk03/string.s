# week 3 tutorial

main:   # length in $t0, s in $t1

        li	$t0, 0			# length = 0
        la      $t1, string             # char *s = &string[0];
loop:
        # loop through all characters in the array to find the length
        lb	$t2, ($t1)		# load byte from ($t1) into $t2
        beqz    $t2, end_loop

        add     $t0, $t0, 1
        add     $t1, $t1, 1

        b	loop			# branch to loop
end_loop:

        move	$a0, $t0		# a = $t0
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        jr      $ra

        .data
string:
        .asciiz "...."
