.DATA
    STR:.ASCIZ "Good_Morning!"
    CHAR:.ASCIZ "w"
    A:.ASCIZ "Character Present"
    B:.ASCIZ "Character Absent"
.TEXT
    LDR R0,=STR
    LDR R4,=CHAR
    loop:   LDRB R2,[R0]
            LDRB R3,[R4]
            CMP R2,#0
            BEQ False
            CMP R2, R3
            BEQ True
            ADD R0, R0, #1
            B loop
    True:   LDR R0,=A
            SWI 0x02
            SWI 0x11
    False:  LDR R0,=B
            SWI 0x02
            SWI 0x11