.syntax unified

.text

.align 8
.global bitAnd_ARM
.func bitAnd_ARM, bitAnd_ARM
.type bitAnd_ARM, %function

bitAnd_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mvn r0, r0      @ get ~x
    mvn r1, r1      @ get ~y
    orr r0, r0, r1  @ get (~x | ~y)
    mvn r0, r0      @ get ~(~x | ~y)

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global getByte_ARM
.func getByte_ARM, getByte_ARM
.type getByte_ARM, %function

getByte_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    lsl r1, r1, #3     @ get the number of bits need to be shifted
    asr r0, r0, r1     @ shift x right
    and r0, r0, #0xff  @ mask x to get one byte 

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global logicalShift_ARM
.func logicalShift_ARM, logicalShift_ARM
.type logicalShift_ARM, %function

logicalShift_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mvn r4, r1
    add r4, r4, #1   @ get negative n

    add r5, r4, #32  @ get (32 - n)

    mvn r6, #0
    lsl r6, r6, r5
    mvn r6, r6       @ get the mask

    asr r0, r0, r1
    and r0, r0, r6   @ get the rsult

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global bitCount_ARM
.func bitCount_ARM, bitCount_ARM
.type bitCount_ARM, %function

bitCount_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mov r4, #0x55
    lsl r4, r4, #8
    add r4, r4, #0x55
    lsl r5, r4, #16
    add r5, r5, r4     @ get the 1st mask

    mov r4, #0x33
    lsl r4, r4, #8
    add r4, r4, #0x33
    lsl r6, r4, #16
    add r6, r6, r4     @ get the 2nd mask

    mov r4, #0xf
    lsl r4, r4, #8
    add r4, r4, #0xf
    lsl r7, r4, #16
    add r7, r7, r4     @ get the 3rd mask

    mov r8, #0xff
    lsl r8, r8, #16
    add r8, r8, #0xff  @ get the 4th mask

    mov r9, #0xff
    lsl r9, r9, #8
    add r9, r9, #0xff  @ get the 5th mask

    and r10, r0, r5
    asr r11, r0 , #1
    and r11, r11, r5
    add r0, r10, r11

    and r10, r0, r6
    asr r11, r0, #2
    and r11, r11, r6
    add r0, r10, r11

    and r10, r0, r7
    asr r11, r0, #4
    and r11, r11, r7
    add r0, r10, r11

    and r10, r0, r8
    asr r11, r0, #8
    and r11, r11, r8
    add r0, r10, r11

    and r10, r0, r9
    asr r11, r0, #16
    and r11, r11, r9
    add r0, r10, r11

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global fitsBits_ARM
.func fitsBits_ARM, fitsBits_ARM
.type fitsBits_ARM, %function

fitsBits_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mvn r4, #0

    mvn r5, r1
    add r5, r5, #1     @ get negative n
    add r5, r5, #33    @ get (33 - n)
    lsl r5, r4, r5
    mvn r5, r5         @ get the mask

    add r6, r1, r4     @ get (n - 1)
    asr r6, r0, r6
    and r6, r6, r5     @ get the first (33 - n) bits of the number

    asr r7, r0, #31
    and r7, r7, r5     @ get 31 one's or zero's

    eor r8, r6, r7     @ get (r6 ^ r7)

    and r9, r8, #1
    add r9, r9, #1
    asr r9, r9, #1

    mov r10, #1
    lsl r10, r10, #31
    mvn r10, r10
    
    asr r11, r8, #1
    and r11, r11, r10  
    add r11, r11, r10

    add r0, r9, r11
    asr r0, r0, #31
    and r0, r0, #1
    eor r0, r0, #1     @ get !(r6 ^ r7)

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global negate_ARM
.func negate_ARM, negate_ARM
.type negate_ARM, %function

negate_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mvn r0, r0  @ get ~n
    add r0, #1  @ get (~n + 1)

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global isLessOrEqual_ARM
.func isLessOrEqual_ARM, isLessOrEqual_ARM
.type isLessOrEqual_ARM, %function

isLessOrEqual_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    mvn r4, r0
    add r4, r4, #1     @ get negative x
    add r4, r4, r1     @ get (y - x)
    asr r4, r4, #31    @ get the sign of (y - x)
    
    and r9, r4, #1
    add r9, r9, #1
    asr r9, r9, #1

    mov r10, #1
    lsl r10, r10, #31
    mvn r10, r10
    
    asr r11, r4, #1
    and r11, r11, r10  
    add r11, r11, r10  

    add r0, r9, r11
    asr r0, r0, #31
    and r0, r0, #1
    eor r0, r0, #1     @ get !(y - x)

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc


.end
