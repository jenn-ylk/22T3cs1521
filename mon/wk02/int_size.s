
main:
        # TODO: fill this in with number read, and 
        jr      $ra             # return from main

        .data
prompt_str:
        .asciiz "Enter a number: "
medium:
        .asciiz "medium"
small_big:
        .asciiz "small/big"
