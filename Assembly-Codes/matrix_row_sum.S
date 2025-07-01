.DATA 
      A:.word 0x1F,0x3f2,0xED3 
        .word 0xAB2,0xCA3,0xFE4
        .word 0x1A3,0xEDA4,0xDE5
      SUM:.word 0,0,0

.TEXT
    LDR R0,=A
    LDR R1,=SUM
    MOV R2,#0
    MOV R3,#0
    MOV R4,#3
    MOV R5,#3

    LOOP:   MOV R6,#0
            MOV R3,#0
            B INNER
            AFTERINNER: STR R6,[R1,R2,LSL#2]
                        ADD R2,R2,#1
                        CMP R2,R5 
                        BEQ EXIT
                        BNE LOOP

    INNER:  MLA R8,R2,R4,R3
            LDR R7,[R0,R8,LSL#2]
            ADD R6,R6,R7
            ADD R3,R3,#1
            CMP R3,R4
            BEQ AFTERINNER
            BNE INNER

    EXIT:   SWI 0x11