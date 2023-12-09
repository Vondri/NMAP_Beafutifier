#!/bin/bash

if [ "$EUID" -ne 0 ]
	then echo "You must run it as root!"
	exit
fi

g++ main.cpp -o nmap_beautifier 
chmod +x nmap_beautifier
cp nmap_beautifier /usr/bin
