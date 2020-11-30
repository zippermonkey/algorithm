#!/bin/bash
dhcpcd
dd if=/dev/zero of=/swapfile bs=1M count=8192 status=progress
chmod 600 /swapfile
mkswap /swapfile
swapon /swapfile
echo "/swapfile none swap defaults 0 0" >> /etc/fstab
useradd -m -G wheel zippermonkey
passwd zippermonkey
pacman -S sudo
ln -s /usr/bin/vim /usr/bin/vi
visudo
pacman -S xf86-video-ati xf86-video-amdgpu mesa
pacman -S xorg xorg-server
pacman -S plasma-meta kde-applications sddm xf86-input-synaptics xf86-input-libinput sddm-kcm
pacman -S alsa-utils pulseaudio pulseaudio-alsa
systemctl enable sddm
systemctl disable netctl
systemctl enable NetworkManager