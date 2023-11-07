@set RTT_CC=gcc
@set RTT_EXEC_PATH=C:\Program Files (x86)\GNU Tools ARM Embedded\8 2019-q3-aarch64-elf\bin
@set RTT_CC_PREFIX=aarch64-elf-
@set PATH=%RTT_EXEC_PATH%;%ENV_ROOT%\tools\gnu_gcc\arm_gcc\mingw\bin;%PATH%

make
python transcode.py
arm-none-eabi-gcc -march=armv8-a -mfpu=neon-vfpv4 -ftree-vectorize -ffast-math -mfloat-abi=softfp -x assembler-with-cpp -D__ASSEMBLY__ -nostartfiles debug_aarch32.S -o debug_aarch32.o
arm-none-eabi-objdump -d debug_aarch32.o > debug_aarch32.txt
arm-none-eabi-objcopy -O binary debug_aarch32.o ../nuwriter_scripts/debug_aarch32.bin
rm debug_aarch32.S *.o