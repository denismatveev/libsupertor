#ifndef MYAPP_H
#define MYAPP_H
#include "tor_api.h"
#include <curl/curl.h>



void* tor_thread_start(void*);
int torstart(void);
int torstop(void);
int torget(char*); //sends get request
int torpost(char *);//sends post request



#endif
