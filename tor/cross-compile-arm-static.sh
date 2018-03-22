#!/bin/bash
export CPPFLAGS="-I/usr/arm-linux-gnueabihf/include/ -I/home/dmat/projects/libs-cross-compilation/include/openssl -I/home/dmat/projects/curl-arm/include"
export LDFLAGS="-L/usr/arm-linux-gnueabihf/lib"
./autogen.sh && ./configure --enable-static-tor --disable-unittests --disable-system-torrc --with-libevent-dir=/home/dmat/projects/libs-cross-compilation  --enable-static-openssl --with-openssl-dir=/home/dmat/projects/libs-cross-compilation --with-zlib-dir=/home/dmat/projects/libs-cross-compilation --disable-asciidoc --with-libcurl-dir=/home/dmat/projects/curl-arm/lib/.libs/ --with-libpthread-dir=/usr/arm-linux-gnueabihf/lib/ --with-libdl-dir=/usr/arm-linux-gnueabihf/lib/ --with-libm-dir=/usr/arm-linux-gnueabihf/lib/ --with-libc-dir=/usr/arm-linux-gnueabihf/lib/ --with-librt-dir=/usr/arm-linux-gnueabihf/lib/  --host=arm-linux-gnueabihf

