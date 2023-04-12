#!/bin/bash

/usr/bin/gcc -fdiagnostics-color=always -g $1 -o $2 -pthread $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)