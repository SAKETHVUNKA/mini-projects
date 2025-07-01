.DATA
    STR:.ASCIZ "HELLO WORLD"

.TEXT
    LDR R0,=STR
    LOOP:LDRB R2,[R0]
         CMP R2,#0
         BEQ EXIT
         ADD R1,R1,#1
         ADD R0,R0,#1
         B LOOP
    EXIT:SWI 0x11