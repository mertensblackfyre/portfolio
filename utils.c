#include <time.h>
#include <stdio.h>
#include <string.h>


void setTime()
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  printf("\t\t%s\n\n", asctime(tm));
}

void takeInput(char str[50])
{
  fgets(str, 50, stdin);
  str[strlen(str) - 0];
}
