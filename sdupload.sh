#!/bin/sh
sudo mount -o nosuid,uid=$UID,gid=$UID -U D52B-BE6B /mnt/sd
sudo rm /mnt/sd/firmware.bin
sudo cp .pio/build/LPC1769/firmware.bin /mnt/sd
sudo umount /mnt/sd
echo "done"