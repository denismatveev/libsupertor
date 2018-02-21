## How to build static lib ##

````bash
$ make clean;./autogen.sh && ./configure --enable-static-tor --with-libevent-dir=/usr/lib/x86_64-linux-gnu \
							--enable-static-openssl --with-openssl-dir=/usr/lib/x86_64-linux-gnu \
							--with-zlib-dir=/usr/lib/x86_64-linux-gnu \
							--disable-asciidoc --with-libcurl-dir=../curl-7.58.0/lib/.libs/ \
							--with-libpthread-dir=/usr/lib/x86_64-linux-gnu/ \
							--with-libdl-dir=/usr/lib/x86_64-linux-gnu/
$ make -j4;make staticlibs
````
## Linking an app ##
````bash
 $ gcc -static main.c -L. -lsupertor -I../mytor/src/proxytor -I../mytor/src/or/ -o app
````

# Features: #

If run configure with `--enable-static-tor` six system libs will make as static

If specify `--enable-static-libm` configure will search math library in system paths, and if addictionally specify `--with-libm-dir=PATH` configure script will search lib in PATH
If specify `--enable-static-tor` you should also specify paths to libs libevent,libm,libz,openssl,libpthread,libdl using string like
--with-libpthread-dir=PATH to search static library. An example see above.
## How to compile libcurl ##

Due to system installed package with libcurl depend on some another libs you need download sources and compile it before compilinig libsupertor.
Download sources you can here: https://curl.haxx.se/download.html
````bash
$ ./configure --disable-rt --disable-ftp --disable-ldap --disable-ldaps --disable-rtsp --disable-dict \
			  --disable-telnet --disable-tftp --disable-pop3 --disable-imap --disable-smb --disable-smtp \
			  --disable-gopher --disable-sspi --disable-ntlm-wb --disable-tls-srp --without-zlib --disable-threaded-resolver \
			  --disable-file
````
## How to build shared lib ##

````bash
$ ./autogen.sh && ./configure --enable-shared-libs && make -j4
$ make sharedlibs
````

shared lib libsupertor.so located at src/lib/shared/

# How to link an app #
````bash
$ gcc -g main.c -lsupertor -L. -I../mytor/src/proxytor -L../curl-7.58.0/lib/.libs/ -lcurl -levent  -lz -lm -lpthread -o app
````
Also you need custom build of openssl, see above.
To run the app specify export LD_LIBRARY_PATH=`` `pwd` ``

## How to cross-compile ##
# curl cross-compile #
https://curl.haxx.se/docs/install.html

Download and unpack the curl package.

'cd' to the new directory. (e.g. cd curl-7.12.3)

Set environment variables to point to the cross-compile toolchain and call configure with any options you need. Be sure and specify the --host and --build parameters at configuration time. The following script is an example of cross-compiling for the IBM 405GP PowerPC processor using the toolchain from MonteVista for Hardhat Linux.
````bash
#! /bin/sh
export PATH=$PATH:/opt/hardhat/devkit/ppc/405/bin
export CPPFLAGS="-I/opt/hardhat/devkit/ppc/405/target/usr/include"
export AR=ppc_405-ar
export AS=ppc_405-as
export LD=ppc_405-ld
export RANLIB=ppc_405-ranlib
export CC=ppc_405-gcc
export NM=ppc_405-nm
./configure --target=powerpc-hardhat-linux
    --host=powerpc-hardhat-linux
    --build=i586-pc-linux-gnu
    --prefix=/opt/hardhat/devkit/ppc/405/target/usr/local
    --exec-prefix=/usr/local
````
You may also need to provide a parameter like --with-random=/dev/urandom to configure as it cannot detect the presence of a random number generating device for a target system. The --prefix parameter specifies where curl will be installed. If configure completes successfully, do make and make install as usual.

In some cases, you may be able to simplify the above commands to as little as:

````bash
./configure --host=ARCH-OS
````