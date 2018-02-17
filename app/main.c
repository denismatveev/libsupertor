#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
string *s=init_string();
if(torstart())
    return 1;

if(torget(s,"https://66.ru"))
   return 2;
printf("%s\n",s->ptr);
torget(s, "http://psyco2l2lrdxfnee.onion/");
//sleep(15);
printf("%s\n",s->ptr);
//printf("Size:%lu\n",s->len);
torpost("https://yandex.ru", "?fromme&test");
if(torstop())
    return 3;
destroy_string(s);
return 0;



}
