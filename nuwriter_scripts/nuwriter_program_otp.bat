py -3 nuwriter.py -a ddrimg\enc_ddr3_winbond_256mb.bin
IF %ERRORLEVEL% EQU 0 (
    py -3 nuwriter.py -w otp otp-macaddr.txt
)
PAUSE