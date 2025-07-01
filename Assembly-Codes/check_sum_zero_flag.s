.DATA
    A:.WORD 10
    B:.WORD -10
    C:.WORD 100
.TEXT
    LDR R1,=A
    LDR R2,=B
    LDR R3,=C
    ADDS R4,R1,R2
    BNE ELSE
    MOV R5,#1
    B NEXT
    ELSE: MOV R5,#0
    NEXT: STR R5,[R3]
    SWI 0x011