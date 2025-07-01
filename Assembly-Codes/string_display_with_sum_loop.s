.TEXT
    mov r0,#30
    mov r1,#7
    mov r7,#0
    ldr r8,=NUM
    ldr r8,[r8]
    ldr r2,=str

    loop: swi 0x204
        bl sum
        cmp r0,#0
        subne r0,r0,#1
        swieq 0x11
        b loop

    sum: cmp R7,R8
        ADDNE R7,R7,#1
        BNE sum
        SWI 0x206
        MOV R7,#0
        MOV PC,LR

.DATA
    str: .ASCIZ "Hello"
    NUM: .WORD 64000