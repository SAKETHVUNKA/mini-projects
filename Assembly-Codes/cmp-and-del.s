.DATA   
    A:.WORD 2
    B:.WORD 1

.TEXT
    LDR R0,=A
    LDR R1,=B
    LDR R2,[R0]
    LDR R3,[R1]
    CMP R2,R3
    BEQ L1
    BNE L2
    L1: ADD R2,R2,R3
        B L
    L2: SUB R2,R2,R3
    L: SWI 0x011