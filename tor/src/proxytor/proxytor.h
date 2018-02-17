#ifndef MYAPP_H
#define MYAPP_H
#include "tor_api.h"
#include <stdlib.h>
#include<string.h>
#include <curl/curl.h>


typedef struct _string {
  char *ptr;
  size_t len;
} string ;
string* init_string(void);
void destroy_string(string*);
size_t writefunc(char*, size_t, size_t, void*);

void* tor_thread_start(void*);
int torstart(void);
int torstop(void);
int torget(string *s,const char*); //sends get request
int torpost(const char *, const char *);//sends post request
#endif
