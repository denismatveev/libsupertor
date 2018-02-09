#ifndef MYAPP_H
#define MYAPP_H
#include "tor_api.h"
void* tor_thread_start(void*);
//int torstart(tor_main_configuration_t*);
int torstart(void);
int torstop(void);
//int torget(char*); //sends get request
//int torpost(char *);//sends post request



#endif
