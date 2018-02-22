#!/bin/bash
export CPPFLAGS="-I/usr/arm-linux-gnueabihf/include/ -I/home/dmat/projects/libs-cross-compilation/include/openssl -I/home/dmat/projects/curl-7.58.0/include"
export LDFLAGS="-L/usr/arm-linux-gnueabihf/lib"
./autogen.sh && ./configure --enable-static-tor --with-libm-dir=/usr/arm-linux-gnueabihf/lib/  --with-libevent-dir=/home/dmat/projects/libs-cross-compilation  --enable-static-openssl --with-openssl-dir=/home/dmat/projects/libs-cross-compilation --with-zlib-dir=/home/dmat/projects/libs-cross-compilation --disable-asciidoc --with-libcurl-dir=../curl-7.58.0/lib/.libs/ --with-libpthread-dir=/usr/arm-linux-gnueabihf/lib/ --with-libdl-dir=/usr/arm-linux-gnueabihf/lib/ --host=arm-linux-gnueabihf

