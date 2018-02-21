# How to build static lib #

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
# How to compile libcurl #

Due to system installed package with libcurl depend on some another libs you need download sources and compile it before compilinig libsupertor.
Download sources you can here: https://curl.haxx.se/download.html
````bash
$ ./configure --disable-rt --disable-ftp --disable-ldap --disable-ldaps --disable-rtsp --disable-dict \
			  --disable-telnet --disable-tftp --disable-pop3 --disable-imap --disable-smb --disable-smtp \
			  --disable-gopher --disable-sspi --disable-ntlm-wb --disable-tls-srp --without-zlib --disable-threaded-resolver \
			  --disable-file
````
# How to build shared lib #

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

# How to cross-compile #
## curl cross-compile ##
https://curl.haxx.se/docs/install.html

Download and unpack the curl package.

'cd' to the new directory. (e.g. cd curl-7.12.3)
Just run script cross-compilation-arm.sh

Necessary script is available in ````libcurl```` subdirectory.