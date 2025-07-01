.DATA   
    A:.WORD 1,-2,3,-4,5,0,7,-8,0,-10
.TEXT
    LDR R1,=A
    MOV R0,#0
    MOV R2,#0
    MOV R3,#0
    MOV R4,#0
    MOV R9,#0
    WHILE: LDR R5,[R1]
           CMP R5,R0
           BEQ ZERO
           BGT GREATER
           ADD R4,R4,#1
           ADD R9,R9,#1
           CMP R9,#10
           ADD R1,R1,#4
           BNE WHILE
           B LAST
    ZERO: ADD R3,R3,#1
          ADD R9,R9,#1
          CMP R9,#10
          ADD R1,R1,#4
          BNE WHILE
          B LAST
    GREATER: ADD R2,R2,#1
             ADD R9,R9,#1
             CMP R9,#10
             ADD R1,R1,#4
             BNE WHILE
             B LAST
    LAST: SWI 0x011