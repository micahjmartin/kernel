#!/bin/bash
pkgs="nasm gcc make qemu"
command -v 'apt' 2>/dev/null >/dev/null;
if [ $? == 0 ]; then
    COM="apt ";
fi
command -v 'yum' 2>/dev/null >/dev/null;
if [ $? == 0 ]; then
    COM="yum ";
fi
$COM install -y $pkgs;
