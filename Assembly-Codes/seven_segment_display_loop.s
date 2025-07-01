.TEXT
;.global_start

begin:  mov r0,#0
        mov r2,#0

again:  SWI 0X202
        CMP r0,#1
        BEQ loop1
        CMP r0,#2
        beq loop2
        b again

loop1:  mov r5,#16
        LDR r1,=zero

back1: ldrb r0,[r1]
        SWI 0x200
        bl delay
        add r1,r1,#1
        sub r5,r5,#1
        CMP r5,#0
        BNE back1
        B again

loop2: MOV r5,#16
        LDR r1,=F

back2: ldrb r0,[r1]
        swi 0x200
        bl delay
        sub r1,r1,#1
        sub r5,r5,#1
        CMP r5,#0
        bne back2
        b again
        
delay: mov r4,#32000
        mov r4,#64000
loop3: sub r4,r4,#1
        cmp r4,#0
        bge loop3
        mov pc,LR


.DATA
    zero: .BYTE 0b11101101
    one: .BYTE 0b01100000
    two: .BYTE 0b11001110
    three: .BYTE 0b11101010
    four: .BYTE 0b01100011
    five: .BYTE 0b10101011
    six: .BYTE 0b10101111
    seven: .BYTE 0b11100000
    eight: .BYTE 0b11101111
    nine: .BYTE 0b11101011
    A: .BYTE 0b11110111
    B: .BYTE 0b11111111
    C: .BYTE 0b10011101
    D: .BYTE 0b11111101
    E: .BYTE 0b10011111
    F: .BYTE 0b10010111


    