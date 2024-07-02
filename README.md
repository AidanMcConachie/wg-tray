# Wireguard Tray (Version 0.1)
A simple Qt-based wireguard tool to easily switch configuration files

> This application is developed to run on **Linux only**, wayland is suggested

## Required Dependendencies
- gcc
- make
- sudo
- foot
- wireguard-tools

## Copying existing wireguard files
To copy wireguard files to configurate wireguard-tray, run wg-tray, then run the following command in your preferred terminal

```$ sudo cp /etc/wireguard $HOME/.config/wg-tray/wireguard-configs```

if you do not have any existing wireguard files, put all new wireguard .conf files in the .config/wg-tray/wireguard-configs directory


