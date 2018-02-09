#include "proxytor.h"
#include <pthread.h>
#include "tor_api.h"
#include <stdlib.h>
#include <stdio.h>
/*
int torstart(tor_main_configuration_t* cfg)
{
    int ret;

    if(!(ret = tor_run_main(cfg)))
        return -1;

    return 0;

}
*/
static pthread_t tid;
static tor_main_configuration_t *cfg;
void* tor_thread_start(void* arg)
{
    cfg = tor_main_configuration_new();
    tor_run_main(cfg);


}
int torstart(void)
{
    int rc;
    pthread_attr_t attr;
    if((rc=pthread_attr_init(&attr)))
        return rc;
fclose(stdout);
fclose(stdin);
fclose(stderr);
    if((rc=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)))
        return rc;
     if((rc=pthread_create(&tid, &attr, tor_thread_start, NULL)))
         return rc;


    return 0;

}

int torstop()
{
    int rc;
    tor_main_configuration_free(cfg);
    if((rc=pthread_cancel(tid)))
        return rc;


    return 0;
}

