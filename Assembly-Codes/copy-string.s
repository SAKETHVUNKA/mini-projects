.DATA
    S1:.ASCIZ "Hello World"
    S2:.ASCIZ ""

.TEXT
    LDR R1,=S1
    LDR R3,=S2
    MOV R0,#0
    LOOP:  LDRB R2,[R1],#1
           CMP R2,#0
           BEQ EXIT
           STRB R2,[R3]
           ADD R3,R3,#1
           B LOOP
    EXIT:  STRB R2,[R3]
           SWI 0X11