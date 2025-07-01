.DATA   
    A:.WORD 1,2,3,4,5,6,7,8,9,10,11,12
    B:.WORD 0,0,0,0,0,0,0,0,0,0,0,0

.TEXT
    LDR R0,=A
    LDR R5,=B
    MOV R9,#0
    LL: LDMIA R0,{R1-R4}
        STMIA R5,{R1-R4} ;you can use exclamatory after r5 or use the line below  
        ADD R5,R5,#16
        ADD R0,R0,#16
        ADD R9,R9,#1
        CMP R9,#3
    BNE LL
    SWI 0x011