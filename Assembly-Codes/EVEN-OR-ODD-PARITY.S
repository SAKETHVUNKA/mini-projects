.DATA   
    A:.WORD 3

.TEXT
    LDR R0,=A
    MOV R6,#32
    MOV R3,#0
    MOV R2,#0
    MOV R10,#0
    LDR R2,[R0]
    MOV R4,#1
    L:  AND R8,R2,#1
        CMP R8,R4
        BNE LAST
        ADD R3,R3,#1
        LAST:   SUB R6,R6,#1
                CMP R6,R10
                BEQ LL
                MOV R2, R2, LSR #1
                B L
    LL: AND R7,R3,#1
        CMP R7,R4
        BNE EVEN
        MOV R5,#1
        B E
        EVEN: MOV R5,#0 
    E: SWI 0x011