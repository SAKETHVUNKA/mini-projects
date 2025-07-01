.DATA
    A:.word 0x1F,0x3f2,0xED3 
      .word 0xAB2,0xCA3,0xFE4 
      .word 0x1A3,0xEDA4,0xDE5 
    B:.word

.TEXT

    MOV R0,#1 
    MOV R1,#2 
    MOV R2,#3 
    LDR R3,=A
    LDR R4,=B
    MLA R5,R0,R2,R1
    LDR R6,[R3,R5,LSL#2]
    STR R6,[R4]
    SWI 0x11