.DATA 
    X:.WORD 12
    Y:.WORD 6
    Z:.WORD -1
.TEXT
    LDR R1,=X
    LDR R2,=Y
    LDR R3,=Z
    LDR R4,[R1]
    LDR R5,[R2]
    WHILE:  CMP R5,R4
            BEQ RESULT
            CMP R4,R5
            BGT GREAT
            LESS: SUB R5,R5,R4
                   B LAST
            GREAT: SUB R4,R4,R5
            LAST: B WHILE               
    RESULT: STR R4,[R3]
    SWI 0x011