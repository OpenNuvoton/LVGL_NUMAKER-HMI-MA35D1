.section ".text.entrypoint"
.globl system_vectors

ma35d1_start:
    .word    0x10000014
    .word    0x9100029f
    .word    0xd5384240
    .word    0xd342fc00
    .word    0x92400400
    .word    0xf1000c1f
    .word    0x54000741
    .word    0xd539f220
    .word    0xb27a0000
    .word    0xd519f220
    .word    0xd5033fdf
    .word    0xd53800a1
    .word    0x92400421
    .word    0xb4000041
    .word    0x14000014
    .word    0xd2800980
    .word    0xf2a808c0
    .word    0xaa1f03e1
    .word    0xb9000001
    .word    0xd282000a
    .word    0xd100054a
    .word    0xf100015f
    .word    0x54000180
    .word    0xd2800900
    .word    0xf2a808c0
    .word    0xaa1403e1
    .word    0xb9000001
    .word    0xd503209f
    .word    0x91001000
    .word    0xb9400002
    .word    0xeb02003f
    .word    0x54fffea1
    .word    0xd503207f
    .word    0x17ffffff
    .word    0xd2836000
    .word    0xf2a016e0
    .word    0xd51be000
    .word    0xd2a00600
    .word    0xd5181040
    .word    0xaa1f03e0
    .word    0xb2630000
    .word    0xb2640000
    .word    0xb2690000
    .word    0xb26a0000
    .word    0xb26c0000
    .word    0xb2750000
    .word    0xd5181000
    .word    0xaa1f03e0
    .word    0xb2770000
    .word    0xb2780000
    .word    0xb2790000
    .word    0xb27b0000
    .word    0xb27c0000
    .word    0xd51e1100
    .word    0xaa1f03e0
    .word    0xd2800060
    .word    0xb2780000
    .word    0xb2790000
    .word    0xb27a0000
    .word    0xb27c0000
    .word    0xd51e4000
    .word    0x10000400
    .word    0xd51e4020
    .word    0xd69f03e0
    .word    0xd53ce100
    .word    0xb2400400
    .word    0xd51ce100
    .word    0xd51ce07f
    .word    0xd5380000
    .word    0xd53800a1
    .word    0xd51c0000
    .word    0xd51c00a1
    .word    0xd2867fe0
    .word    0xd51c1140
    .word    0xd51c117f
    .word    0xd2a00600
    .word    0xd5181040
    .word    0xd2800000
    .word    0xb2630000
    .word    0xd51c1100
    .word    0xd53c1100
    .word    0xd2810000
    .word    0xf2a61a00
    .word    0xd5181000
    .word    0x910003e0
    .word    0xd51c4100
    .word    0xd53cc000
    .word    0xd518c000
    .word    0xd2803a60
    .word    0xd51c4000
    .word    0x10000060
    .word    0xd51c4020
    .word    0xd69f03e0

.L__aarch32_code:

    mov     r0,  #0
    mov     r1,  #0
    mov     r2,  #0
    mov     r3,  #0
    mov     r4,  #0
    mov     r5,  #0
    mov     r6,  #0
    mov     r7,  #0
    mov     r8,  #0
    mov     r9,  #0
    mov     r10, #0
    mov     r11, #0
    mov     r12, #0
    mcr     p15, 0, r0, c1, c0, 0
    isb
    vmrs    r1, FPEXC
    orr     r1, r1, #(1 << 30)
    vmsr    FPEXC, r1
    bl      system_vectors
