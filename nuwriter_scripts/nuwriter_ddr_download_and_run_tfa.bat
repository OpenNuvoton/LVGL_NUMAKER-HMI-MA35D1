:forever_develop
py -3 nuwriter.py -a ddrimg\enc_ddr3_winbond_256mb.bin
IF %ERRORLEVEL% EQU 0 (
   py -3 nuwriter.py -w ddr 0x80800000 ..\rtthread.bin
   py -3 nuwriter.py -w ddr 0x86000000 .\tfa\fip.bin-nand

   py -3 nuwriter.py -w ddr 0x28023000 .\tfa\bl2-700Mhz-ma35d1.dtb
   py -3 nuwriter.py -o execute -w ddr 0x28000000 .\tfa\bl2-ma35d1.bin
)
pause

goto :forever_develop
