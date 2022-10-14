# week 3 tutorial - processes the length of a string

main:   # length in $t0, s in $t1

        li	$t0, 0			# length = 0
        la      $t1, string             # char *s = &string[0];
loop:
        # loop through all characters in the array to find the length
        lb	$t2, ($t1)		# load byte from ($t1) into $t2
        beqz    $t2, end_loop           # if (*s == 0) goto end_loop;

        add     $t0, $t0, 1             # length++;
        add     $t1, $t1, 1             # s++;

        b	loop			# branch to loop
end_loop:

        move	$a0, $t0		# printf("%d\n" length);
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        jr      $ra

        .data
string:
        .asciiz "...."
