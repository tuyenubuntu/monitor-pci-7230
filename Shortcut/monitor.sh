#!/bin/bash
echo Monitor IO card PCI-7230
source ~/anaconda3/etc/profile.d/conda.sh
conda activate monitor  # Activate conda environment
python3 /home/itmop/Documents/monitor-pci-7230/app.py  # Run application