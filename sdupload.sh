#!/bin/sh
sudo mount -U 9211-92DF /mnt/sd
sudo rm /mnt/sd/firmware.bin
sudo cp .pio/build/STM32F103RC_btt_512K/firmware.bin /mnt/sd
sudo umount /mnt/sd
echo "done"