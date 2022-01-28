.ORIG x3000
;Caller (User) - makes the call
;Callee (TRAP) - being called

;Saving Registers
AND R0, R0, #0
AND R0, R0, #3
ADD R7, R0, #2
ADD R0, R0, #1
ADD R7, R7, #1

; Storing/Save Registers
ST R0, SAVE_R0
ST R7, SAVE_R7

IN

; Restore Registers
LD R0, SAVE_R0
LD R7, SAVE_R7

ADD R0, R0, #1
ADD R7, R7, #1

HALT

SAVE_R0 .BLKW #1
SAVE_R7 .BLKW #1

.END