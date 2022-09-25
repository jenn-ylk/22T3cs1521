# Prints the square of a number

# Types of comments to leave in your code:
#  - equivalent code in c
#  - variables in the registers
#  - function related comments (parameters, stack info, clobbers)

main:                           # x,y in $t0, $t1
        la      $a0, prompt_str # printf("Enter a number: ");
        li	$v0, 4	        
        syscall

        li      $v0, 5          # scanf("%d", &x)
        syscall
        move	$t0, $v0
        
        bgt     $t0, 46340, too_big

        mul     $t1, $t0, $t0   # y = x * x

        move    $a0, $t1        # printf("%d\n", y);
        li      $v0, 1
        syscall
        li      $a0, '\n'
        li      $v0, 11
        syscall

        b finish

too_big:
        la      $a0, alert_too_big
        li	$v0, 4	        
        syscall


finish:

        jr      $ra             # return from main

        .data
prompt_str:
        .asciiz "Enter a number: "
alert_too_big:
        .asciiz "square too big for 32 bits\n"
