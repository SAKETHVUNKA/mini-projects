.DATA   
    A:.WORD 2
    C:.ASCIZ "EVEN"
    B:.ASCIZ "ODD"

.TEXT
    LDR R0,=A
    MOV R1,#1
    LDR R2,[R0]
    MOV R4,#1
    AND R3,R2,#1
    CMP R3,R4
    BEQ L1
    LDR R0,=C
    SWI 0X02
    B L
    L1: 
    LDR R0,=B
    SWI 0X02
    L: SWI 0x011