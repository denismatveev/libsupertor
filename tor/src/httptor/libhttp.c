#include "libhttp.h"


int torstart(tor_main_configuration_t* cfg)
{
    int ret;

    if(!(ret = tor_run_main(cfg)))
        return -1;

    return 0;

}

int torstop(tor_main_configuration_t* cfg)
{
    tor_main_configuration_free(cfg);

    return 0;
}
