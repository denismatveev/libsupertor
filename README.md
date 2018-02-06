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
gcc main.c -I. -L. -ltor -lor -lor-event -lor-crypto -levent -lpthread -lor-ctime -lor-trunnel -lm -lz -lssl -lcrypto  -lkeccak-tiny -lcurve25519_donna -led25519_donna -led25519_ref10 -lpthread -static -o myapp
````
# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

* Quick summary
* Version
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact
