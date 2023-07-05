# -*- coding: UTF-8 -*- 

import os

def extract_line(fname, pattern):
    with open(fname, "r") as f:
        lines = f.readlines()
        f.close()
    with open("entry_point.S", "w") as f:
        counter=0
        f.write(".section \".text.entrypoint\"\n")
        f.write(".globl system_vectors\n")
        f.write("\n")
        f.write("ma35d1_start:\n")
        for line in lines:
            if pattern in line:
                new_line = "    .word    0x" + line[6:14] + "\n"
                f.write(new_line)
                counter = counter+1
        f.write("\n")
        f.write(".L__aarch32_code:\n")
        f.write("\n")
        f.write("    mov     r0,  #0\n");
        f.write("    mov     r1,  #0\n");
        f.write("    mov     r2,  #0\n");
        f.write("    mov     r3,  #0\n");
        f.write("    mov     r4,  #0\n");
        f.write("    mov     r5,  #0\n");
        f.write("    mov     r6,  #0\n");
        f.write("    mov     r7,  #0\n");
        f.write("    mov     r8,  #0\n");
        f.write("    mov     r9,  #0\n");
        f.write("    mov     r10, #0\n");
        f.write("    mov     r11, #0\n");
        f.write("    mov     r12, #0\n");
        f.write("    mcr     p15, 0, r0, c1, c0, 0\n");
        f.write("    isb\n");
        f.write("    vmrs    r1, FPEXC\n");
        f.write("    orr     r1, r1, #(1 << 30)\n");
        f.write("    vmsr    FPEXC, r1\n");
        f.write("    bl      system_vectors\n");

        # Append NOP to align vector table.
        f.close()

def formatfiles():
    extract_line("preload.txt", ":\t")

if __name__ == '__main__':
    formatfiles()
