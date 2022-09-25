# Prints the square of a number

main:                           # x,y in $t0, $t1
        la      $a0, prompt     # printf("Enter a number: ");
        li      $v0, 4
        syscall

        li      $v0, 5          # scanf("%d", x);
        syscall
        move    $t0, $v0

        ble	$t0, 46340, calc

        la      $a0, toobig
        li      $v0, 4
        syscall
        li      $a0, '\n'
        li      $v0, 11
        syscall

        b	finish		# branch to finish

calc:
        mul     $t1, $t0, $t0   # y = x * x

        move    $a0, $t1        # printf("%d", y);
        li      $v0, 1
        syscall

        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall

finish:
        jr      $ra             # return from main

        .data
prompt:
        .asciiz "Enter a number: "
toobig:
        .asciiz "square too big for 32 bits"
