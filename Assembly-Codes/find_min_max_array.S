.DATA
    A:.WORD 10,20,30,40,50,60,-200,6000
    SMALL:.WORD 0
    LARGE:.WORD 0

.TEXT
    LDR R0,=A
    LDR R1,[R0];MIN
    LDR R2,[R0];MAX
    MOV R3,#0
    MOV R4,#8
    LDR R5,[R0]
    LDR R6,=SMALL
    LDR R7,=LARGE
    WHILE:  CMP R3,R4
            BEQ DONE
            LDR R5,[R0]
            CMP R5,R1
            BLT SMAL
            B G
            SMAL: MOV R1,R5
            G: CMP R5,R2
               BGT LARG
               ADD R0,R0,#4
               ADD R3,R3,#1
               B WHILE 
               LARG:MOV R2,R5
               ADD R0,R0,#4
               ADD R3,R3,#1
               B WHILE
    DONE: STR R1,[R6]
          STR R2,[R7]
    SWI 0x011