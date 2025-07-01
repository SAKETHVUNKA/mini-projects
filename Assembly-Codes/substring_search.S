.DATA
    TEXT:.ASCIZ "My name is Bond"
    PATTERN:.ASCIZ "James"
    SS:.ASCIZ "String Present"
    FS:.ASCIZ "String Absent"
.TEXT
    LDR R1,=TEXT
    LDR R2,=PATTERN
    FOR:
        LDRB R4, [R2]
        LDRB R3, [R1], #1
        CMP R3, #0
        BEQ FAIL
        CMP R3, R4
        BNE FOR    
        ADD R5, R2, #1
        WHILE:  LDRB R4, [R5], #1 
                LDRB R3, [R1], #1
                CMP R3, #0
                BEQ FAIL
                CMP R4, #0 
                BEQ DONE
                CMP R3, R4
                BEQ WHILE    
                BNE FOR    
    DONE:
        LDR R0,=SS
        SWI 0x02
        SWI 0x11
    FAIL:
        LDR R0,=FS
        SWI 0x02
        SWI 0x11