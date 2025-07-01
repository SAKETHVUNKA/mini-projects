.DATA   
    A:.WORD 10,20,30
    B:.WORD 0,0,0,0

.TEXT
    LDR R0,=A
    LDR R4,=B
    LDMIA R0,{R1-R3}
    STMIA R4,{R1-R3}
    @ LDMIA R4,{R5-R7}
    SWI 0x011