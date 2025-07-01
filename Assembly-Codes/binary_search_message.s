.DATA
        A:.WORD 10,20,30,40,50,60,70
        B:.WORD 11
        SS:.ASCIZ"Successful Search"
        FS:.ASCIZ"Unsuccessful Search"
.TEXT
        MOV R0,#0
        LDR R1,=A
        LDR R2,=B
        MOV R5,#6
        LDR R11,[R2]
        WHILE:  CMP R0,R5
                ADD R8,R5,R0
                MOV R8,R8,LSR #1
                MOV R6,#4
                MUL R8,R6,R8
                MOV R7,#0
                ADD R7,R8,R1
                MOV R8,R8,LSR #2
                BGT DONE
                LDR R9,[R7]
                CMP R11,R9
                BEQ FINAL
                BGT GREATER
                BLT LESSER
                LESSER: MOV R6,#-1 
                        ADD R5,R8,R6
                        B WHILE
                GREATER:MOV R6,#1 
                        ADD R0,R8,R6
                        B WHILE
        DONE:   LDR R0,=FS
                SWI 0x02
                B ENDING
        FINAL:  LDR R0,=SS
                SWI 0x02
        ENDING: SWI 0x011