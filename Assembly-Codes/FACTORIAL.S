.DATA
    A:.WORD 5
    FACT:.WORD 0
.TEXT
    LDR R9,=A
    LDR R8,[R9]
    ADD R8,R8,#1
    LDR R7,=FACT
    MOV R1,#1
    MOV R3,#1
    MOV R4,#1
    WHILE: MUL R1,R4,R3   
           MOV R4,R1        
           ADD R3,R3,#1
           CMP R3,R8
           BNE WHILE
    STR R1,[R7]
    SWI 0x011