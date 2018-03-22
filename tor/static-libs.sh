#!/bin/bash
make clean;./autogen.sh && ./configure --enable-static-tor --with-libevent-dir=/usr/lib/x86_64-linux-gnu \
			    --disable-unittests --disable-asserts-in-tests --disable-system-torrc    \
                            --enable-static-openssl --with-openssl-dir=/usr/lib/x86_64-linux-gnu \
                            --with-zlib-dir=/usr/lib/x86_64-linux-gnu \
                            --disable-asciidoc --with-libcurl-dir=../curl-x86_64/lib/.libs/ \
                            --with-libpthread-dir=/usr/lib/x86_64-linux-gnu/ \
                            --with-libdl-dir=/usr/lib/x86_64-linux-gnu/
make -j4;make staticlibs
