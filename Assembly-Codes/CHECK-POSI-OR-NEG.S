.DATA   
    A:.WORD -2

.TEXT
    LDR R0,=A
    MOV R3,#0
    LDR R2,[R0]
    CMP R2,R3
    BEQ L1
    BGT L2
    MOV R1,#3
    B L
    L1: MOV R1,#1
        B L 
    L2: MOV R1,#2
    L: SWI 0x011