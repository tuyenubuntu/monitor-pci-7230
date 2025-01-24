#!/bin/bash
echo Monitor IO card PCI-7230
source ~/anaconda3/etc/profile.d/conda.sh
conda activate monitor  # Kích hoạt môi trường Conda
python3 /home/itmop/Documents/monitor/app.py  # Chạy chương trình
