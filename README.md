# How To Build static lib #
````bash
$ cd tor
$ ./autogen.sh && ./configure --enable-static-tor \
							--with-libevent-dir=/usr/lib/x86_64-linux-gnu  \
							--enable-static-openssl \
							--with-openssl-dir=/usr/lib/x86_64-linux-gnu/ \
							--with-zlib-dir=/usr/lib/x86_64-linux-gnu \
							--disable-asciidoc
$ make -j4 staticlibs
````
## OR ##

````bash
$ ./autogen.sh &&  ./configure --enable-static-tor --with-libevent-dir=/usr/lib/x86_64-linux-gnu \
								--enable-static-openssl \
								--with-openssl-dir=/usr/lib/x86_64-linux-gnu/ \
								--with-zlib-dir=/usr/lib/x86_64-linux-gnu \
								--disable-asciidoc \
								--enable-static-libm
````
## link app ##
 ````bash
 gcc -static main.c -L. -lsupertor -I../mytor/src/proxytor \ 
 									-I../mytor/src/or/  \
									-lpthread -ldl  \
									-L../curl/lib/.libs/ \
									-l:libcurl.a \
									-lsupertor -lpthread -o app
 ````

## How to link an application ##

````bash
$ gcc main.c -I. -L. -ltor -lor -lor-event -lor-crypto -levent -lpthread -lor-ctime -lor-trunnel -lm -lz -lssl -lcrypto  -lkeccak-tiny -lcurve25519_donna -led25519_donna -led25519_ref10 -lpthread -static -o myapp
````
## Or just using libsupertor ##
````bash
$ gcc -static main.c -L. -lsupertor -o app
````

# Features: #

If run configure with `--enable-static-tor` four system libs will make as static

If specify `--enable-static-libm` configure will search math library in system paths, and if addictionally specify `--with-libm-dir=PATH` configure script will search lib in PATH
