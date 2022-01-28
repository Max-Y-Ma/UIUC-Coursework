.ORIG x3000

JSR SUBTR

HALT

;SUBTR subroutine computes R1 minus R2
;IN: R1, R2
;OUT: R0 <-- (R1 - R2)

SUBTR
    ; Save R2
    ST R2, SAVE_R2

    NOT R2, R2
    ADD R2, R2, #1          ;get -R2
    ADD R0, R1, R2          ;R0 = R1 - R2
    
    ; Restore R2
    LD R2, SAVE_R2

    RET

SAVE_R2 .BLKW #1

.END