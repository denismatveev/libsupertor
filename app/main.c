#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
string *s=init_string();
if(torstart())
    return 1;

//if(torget(s,"https://66.ru"))
//   return 2;
//printf("%s\n",s->ptr);
//if(torget(s, "https://facebookcorewwwi.onion/"))
//    return 3;
if(torget(s,"http://torlinkbgs6aabns.onion/"))
    return 3;
printf("%s\n",s->ptr);
//printf("Size:%lu\n",s->len);
printf("POST to yandex\n");
torpost(s,"https://yandex.ru", "from_me");
printf("%s\n", s->ptr);
if(torstop())
    return 4;
destroy_string(s);
return 0;



}
