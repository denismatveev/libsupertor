#! /bin/sh
export PATH=$PATH:/usr/arm-linux-gnueabihf/bin/
export CPPFLAGS="-I/usr/arm-linux-gnueabihf/include/"
export AR=arm-linux-gnueabihf-ar
export AS=arm-linux-gnueabihf-as
export LD=arm-linux-gnueabihf-ld
export RANLIB=arm-linux-gnueabihf-ranlib
export CC=arm-linux-gnueabihf-gcc
export NM=arm-linux-gnueabihf-nm
./configure --host=arm-linux-gnueabihf --build=x86_64-linux-gnu --disable-rt --disable-ftp --disable-ldap --disable-ldaps --disable-rtsp --disable-dict --disable-telnet --disable-tftp --disable-pop3 --disable-imap --disable-smb --disable-smtp --disable-gopher --disable-sspi --disable-ntlm-wb --disable-tls-srp --without-zlib --disable-threaded-resolver --disable-file
