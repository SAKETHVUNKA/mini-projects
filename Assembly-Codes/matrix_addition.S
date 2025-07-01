.DATA
    A:  .word 0x012,0x030,0x056
        .word 0x056,0x002,0x123
        .word 0x322,0x279,0x102
    B:  .word 0x134,0x203,0x102
        .word 0x102,0x322,0x279
        .word 0x002,0x123,0x322
    C:  .word

.TEXT
    LDR R0,=A
    LDR R1,=B
    LDR R2,=C
    MOV R3,#0
    MOV R4,#0
    MOV R5,#3
    MOV R6,#3
    LOOP:   MOV R4,#0
            B INNER
            AFTERINNER: ADD R3,R3,#1
                        CMP R3,R6
                        BEQ EXIT
                        BNE LOOP

    INNER:  MLA R7,R3,R5,R4
            LDR R8,[R0,R7,LSL#2]
            LDR R9,[R1,R7,LSL#2]
            ADD R10,R9,R8
            STR R10,[R2,R7,LSL#2]
            ADD R4,R4,#1
            CMP R4,R5
            BEQ AFTERINNER
            BNE INNER

    EXIT:   SWI 0x11