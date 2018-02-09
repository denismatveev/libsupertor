#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char ** argv)
{
    //tor_main_configuration_t *cfg = tor_main_configuration_new();
    //torstart(cfg);
int a;
if((a = torstart()))
    return a;
sleep(10);

 if((a=torstop()))
     return a;
sleep(10);
    return 0;



}
