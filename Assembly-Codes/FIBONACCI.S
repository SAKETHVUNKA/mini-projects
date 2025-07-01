.DATA   
    A:.WORD 10
    B:.WORD 0,0,0,0,0,0,0,0,0,0

.TEXT
    LDR R1,=A
    LDR R10,[R1]
    LDR R2,=B
    MOV R3,#0
    MOV R4,#1
    STR R3,[R2],#4
    ADD R3,R3,#2
    LDR R5,=B
    ADD R6,R5,#4
    WHILE: STR R4,[R2],#4
           LDR R11,[R5]
           LDR R12,[R6]

           ADD R4,R11,R12
           ADD R5,R5,#4
           ADD R6,R6,#4
           
           STR R4,[R6]
           ADD R3,R3,#1
           CMP R3,R10
           BNE WHILE
    SWI 0x011