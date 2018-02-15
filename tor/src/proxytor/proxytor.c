#include "proxytor.h"
#include <pthread.h>
#include "tor_api.h"
#include <stdlib.h>
#include <stdio.h>
static pthread_t tid;
static tor_main_configuration_t *cfg;
void* tor_thread_start(void* arg)
{
    char *options[]={"tor", "--quiet"};
    tor_main(1, options);
    return NULL;

}
int torstart(void)
{
    int rc;
    pthread_attr_t attr;
    if((rc=pthread_attr_init(&attr)))
        return rc;
    if((rc=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)))
        return rc;
     if((rc=pthread_create(&tid, &attr, tor_thread_start, NULL)))
         return rc;


    return 0;

}

int torstop(void)
{
    int rc;
    if((rc=pthread_cancel(tid)))
        return rc;

    return 0;
}



string* init_string(void)
{
  string *s;
  if((s = (string*)malloc(sizeof(string))) == NULL)
  {
      fprintf(stderr, "malloc failed\n");
      return NULL;
  }


  s->ptr = (char*)malloc(sizeof(char));
  s->len = 0;
  if (s->ptr == NULL)
  {
    fprintf(stderr, "malloc() failed\n");
    return NULL;
  }

  s->ptr[0] = '\0';

  return s;

}

void destroy_string(string *s)
{
    free(s->ptr);
    free(s);

    return;

}

// callback function prototype
// size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
size_t writefunc(char *ptr, size_t size, size_t nmemb, void *st)
{
 
  size_t realsize = size * nmemb;
  string *s=(string*)st;
  char* newptr;

  newptr =(char*)realloc(s->ptr,(s->len + nmemb + 1)*sizeof(char));
  if(newptr == NULL) 
  {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
  s->ptr=newptr;

  memcpy(&(s->ptr[s->len]), ptr, realsize);
  s->len += nmemb;
  s->ptr[s->len] = 0;

  return realsize;
}


int torget(string *res, const char* req)
{

CURL *curl = curl_easy_init();
CURLcode ret;


if(curl)
 {
 
  if((ret = curl_easy_setopt(curl, CURLOPT_URL, req)))
      return ret;

  if((ret=curl_easy_setopt(curl, CURLOPT_PROXY, "socks5://127.0.0.1")))
      return ret;

  if((ret=curl_easy_setopt(curl, CURLOPT_PROXYPORT, 9050)))
      return ret;
  if((ret=curl_easy_setopt(curl, CURLOPT_USERAGENT, "libsupertor/1.0")))
      return ret;
 if((ret=curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc)))
    return ret;
 if((ret=curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)res)))
    return ret;

  if((ret = curl_easy_perform(curl)))
      return ret;
  
  curl_easy_cleanup(curl);
}

return 0;

}

/*

int torpost(const char* req)
{
	CURL *curl;
  CURLcode res;
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, req);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;

}
*/

