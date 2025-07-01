.DATA   
    A:.WORD 1,2,3,4,5,6,7,8,9,10
    ELE:.WORD 1
    SS:.ASCIZ"SUCCESSFUL ."
    FS:.ASCIZ"NOT SUCCESSFUL ."
.TEXT
    LDR R1,=A
    LDR R2,=ELE
    MOV R3,#0
    MOV R4,#1
    MOV R9,#1
    LDR R6,[R2]
    WHILE: LDR R5,[R1]
           CMP R5,R6
           BEQ FOUND
           ADD R1,R1,#4
           ADD R4,R4,#1
           CMP R4,#10
           BNE WHILE
           B NOTFOUND
    FOUND: LDR R0,=SS
           SWI 0x02
           B LAST
    NOTFOUND: LDR R0,=FS
              SWI 0x02
              B LAST
    LAST: SWI 0x011
    .END

    