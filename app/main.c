#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
int a;
if((a = torstart()))
    return a;
sleep(10);

torget("http://ya.ru");

 if((a=torstop()))
     return a;
sleep(10);
    return 0;



}
