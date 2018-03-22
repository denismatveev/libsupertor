#!/bin/bash
export CPPFLAGS="-I/usr/arm-linux-gnueabihf/include/ -I/home/dmat/projects/libs-cross-compilation/include/openssl -I/home/dmat/projects/curl-arm/include"
export LDFLAGS="-L/usr/arm-linux-gnueabihf/lib -L/home/dmat/projects/libs-cross-compilation"
./autogen.sh && ./configure --disable-asciidoc --enable-shared-libs --host=arm-linux-gnueabihf --disable-unittests --disable-system-torrc 
