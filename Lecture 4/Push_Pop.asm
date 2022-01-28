.ORIG x3000

;PUSH Subroutine
ADD R6, R6, #-1     ;decrement stack ptr
STR R0, R6, #0      ;store data (to Top of Stack)

;POP Subroutine
LDR R0, R6, #0      ;load data from stack ptr
ADD R6, R6, #1      ;increment stack ptr

;INPUT: A, B, C
;OUTPUT: B, C, A
;
;Push A
;Push B
;Pop
;Push C
;Pop
;Pop

 HALT

.END