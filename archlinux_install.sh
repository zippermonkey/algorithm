#!/bin/bash
echo "############## install setting ###############"
dhcpcd
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
hwclock --systohc
pacman -S vim dialog wpa_supplicant ntfs-3g networkmanager netctl
vim /etc/locale.gen
echo "LANG=en_US.UTF-8" >> /etc/locale.conf
echo "Magicbook" >> /etc/hostname

echo "127.0.0.1	localhost
::1		localhost
127.0.1.1	myhostname.localdomain	myhostname
" >> /etc/hosts
pacman -S amd-ucode os-prober grub efibootmgr
grub-install --target=x86_64-efi --efi-directory=/boot --bootloader-id=grub
grub-mkconfig -o /boot/grub/grub.cfg
