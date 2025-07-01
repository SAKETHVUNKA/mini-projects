.DATA   
    A:.WORD 100

.TEXT
    LDR R0,=A
    MOV R3,#0
    LDR R2,[R0]
    CMP R2,R3
    BGE L1
    MOV R5,#-1
    B L2
    L1: MOV R5,#1
    L2: SWI 0x011