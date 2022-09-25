# takes in an integer and determines whether it is medium sized, or small/big

main:
        la      $a0, prompt     # printf("Enter a number: ");
        li      $v0, 4
        syscall

        jr      $ra             # return from main

        .data
prompt_str:
        .asciiz "Enter a number: "
medium:
        .asciiz "medium"
small_big:
        .asciiz "small/big

