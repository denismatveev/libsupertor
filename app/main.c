#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
int a;
string *s;
if((a = torstart()))
    return a;
sleep(10); //wait while tor is being initialized

torget(s,"http://ya.ru");
fprintf(stdout,"%s",s->ptr);

 if((a=torstop()))
     return a;
sleep(1);
destroy_string(s);
    return 0;



}
