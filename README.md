# How To Build #
````bash
$ cd tor
$ ./autogen.sh && ./configure --enable-static-tor \
							--with-libevent-dir=/usr/lib/x86_64-linux-gnu  \
							--enable-static-openssl \
							--with-openssl-dir=/usr/lib/x86_64-linux-gnu/ \
							--with-zlib-dir=/usr/lib/x86_64-linux-gnu \
							--disable-asciidoc
$ make
````
````bash
## How to link an application ##
gcc main.c -I. -L. -ltor -lor -lor-event -lor-crypto -levent -lpthread -lor-ctime -lor-trunnel -lm -lz -lssl -lcrypto  -lkeccak-tiny -lcurve25519_donna -led25519_donna -led25519_ref10 -lpthread -static -o myapp
````
