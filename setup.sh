#!/bin/bash
pkgs="nasm gcc make qemu"
command -v 'apt' 2>/dev/null >/dev/null;
if [ $? == 0 ]; then
    COM="apt -qq";
fi
command -v 'yum' 2>/dev/null >/dev/null;
if [ $? == 0 ]; then
    COM="yum -q";
fi
$COM install -qqy $inst;
