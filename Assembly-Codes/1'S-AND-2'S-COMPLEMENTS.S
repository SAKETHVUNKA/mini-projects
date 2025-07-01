.DATA   
    A:.WORD 2

.TEXT
    LDR R0,=A
    LDR R1,[R0]
    MVN R2,R1
    ADD R3,R2,#1
    SWI 0x011