#ifndef MYAPP_H
#define MYAPP_H
#include "tor_api.h"


int torstart(tor_main_configuration_t*);
int torstop(tor_main_configuration_t *);
int torget(char*); //sends get request
int torpost(char *);//sends post request



#endif
