#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
int a;
string *s=init_string();
torstart();
sleep(10); //wait while tor is being initialized

torget(s,"https://66.ru");
//sleep(15);
printf("%s\n",s->ptr);
printf("Size:%lu\n",s->len);
//torget(s, "http://psyco2l2lrdxfnee.onion/");
//sleep(15);
//printf("%s\n",s->ptr);
//printf("Size:%lu\n",s->len);
torstop();
destroy_string(s);
return 0;



}
