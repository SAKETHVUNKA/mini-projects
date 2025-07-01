.DATA
    STR:.ASCIZ "Hello World!"
    CHAR:.ASCIZ "l"
    
.TEXT
    LDR R0,=STR
    LDR R4,=CHAR 
    LOOP:   LDRB R2,[R0]
            LDRB R3,[R4]
            CMP R2,#0    
            BEQ EMPTY
            CMP R2,R3
            BEQ AD
    NORMAL: ADD R0,R0,#1
            B LOOP
    
    AD: ADD R1,R1,#1
        B NORMAL

    EMPTY:  SWI 0x11