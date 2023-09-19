#!/bin/bash

set -x -e

python3 nuwriter.py -c header-spinor.json

python3 nuwriter.py -p pack-spinor.json

python3 nuwriter.py -a ddrimg/enc_ddr3_winbond_256mb.bin

python3 nuwriter.py -w spinand pack/pack.bin
