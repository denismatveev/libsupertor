#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
int a;
string *s=init_string();
if((a = torstart()))
    return a;
sleep(3); //wait while tor is being initialized

torget(s,"http://ya.ru");
printf("Len:%lu\n", s->len);
printf("Output:%s\n",s->ptr);

 if((a=torstop()))
     return a;
destroy_string(s);
printf("String destroyed\nn");
return 0;



}
