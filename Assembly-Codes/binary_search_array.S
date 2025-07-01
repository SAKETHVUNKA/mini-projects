.DATA
        A:.WORD 10,20,30,40,50,60,70
        B:.WORD 21
        C:.WORD -100
.TEXT
        MOV R0,#0
        LDR R1,=A
        LDR R2,=B
        LDR R3,=C
        MOV R4,R1
        MOV R5,#6
        MOV R6,#1
        MUL R5,R6,R5
        MOV R7,R5
        MOV R8,#0
        ADD R8,R0,R5
        MOV R8,R8,LSR #1
        MOV R7,R7,LSR #1
        MOV R6,#4
        MUL R7,R6,R7
        ADD R7,R7,R1
        LDR R11,[R2]
        MOV R6,#4
        WHILE:  CMP R0,R5
                BGT DONE
                LDR R9,[R7]
                CMP R11,R9
                BEQ FINAL
                BGT GREATER
                BLT LESSER
                LESSER:   MOV R6,#-1 
                          ADD R5,R8,R6
                          ADD R8,R5,R0
                          MOV R8,R8,LSR #1
                          MOV R6,#4
                          MUL R8,R6,R8
                          MOV R7,#0
                          ADD R7,R8,R1
                          MOV R8,R8,LSR #2
                          B WHILE
                GREATER:MOV R6,#1 
                        ADD R0,R8,R6
                        ADD R8,R5,R0
                        MOV R8,R8,LSR #1
                        MOV R6,#4
                        MUL R8,R6,R8
                        MOV R7,#0
                        ADD R7,R8,R1
                        MOV R8,R8,LSR #2
                        B WHILE
        DONE: MOV R12,#-1
              STR R12,[R3]
              B ENDING
        FINAL: SUB R10,R7,R1
               MOV R10,R10,LSR #2;HOW TO DIVIDE BY 4
               STR R10,[R3]
        ENDING: SWI 0x011