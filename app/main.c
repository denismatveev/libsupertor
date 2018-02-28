#include "proxytor.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
    char *reqtype, *url;
    char* help_string="How to use:\n"
                  "app [get|post] [url] [data to post]\n";
if(argc < 3)
{
    fprintf(stderr,"%s", help_string);
    exit(1);
}
else
{
    reqtype = argv[1];//get or post
    url = argv[2];
}
int check_url(char* url)
{

    if((strlen(url) == 0))
    {
        fprintf(stderr,"You must specify url\n");
        fprintf(stderr, "%s",help_string);
        return 1;
    }
    return 0;

}

if(argc >=4 && (!(strncasecmp("post", reqtype, 4))))
{
    string *s=init_string();
    if(torstart())
        exit(5);
    char * what2post=argv[3];
    if((strlen(what2post)) == 0)
    {
        fprintf(stderr,"You must specify data to post\n");
        fprintf(stderr,"%s", help_string);
        exit(1);
    }
    if((check_url(url)))
        exit(2);
    if((torpost(s,url, what2post)))
        exit(3);
    printf("%s\n",s->ptr);
    if(torstop())
        exit(4);
    destroy_string(s);
}
else if(argc >= 3 && (!(strncasecmp("get",reqtype,3))))
{

    if((check_url(url)))
        exit(1);
    string *s=init_string();

    if(torstart())
        exit(2);

    if(torget(s,url))
        exit(3);

    printf("%s\n",s->ptr);

    if(torstop())
        exit(4);
    destroy_string(s);
}
else
{
fprintf(stderr, "You must specify get or post(case insensitive)\n");
fprintf(stderr, "%s",help_string);
}
//if(torstart())
//    return 1;
//if(torget(s,"https://66.ru"))
//   return 2;
//printf("%s\n",s->ptr);
//if(torget(s, "https://facebookcorewwwi.onion/"))
//    return 3;
//if(torget(s,"http://torlinkbgs6aabns.onion/"))
//    return 3;
//printf("%s\n",s->ptr);
//printf("Size:%lu\n",s->len);
//printf("POST to yandex\n");
//torpost(s,"https://yandex.ru", "from_me");
//printf("%s\n", s->ptr);
return 0;

}
