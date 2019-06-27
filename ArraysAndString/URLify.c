
/*
Question:
replace the spaces from the string with "%20" string
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

char *URLify(char *, int);

int main()
{
  char *str = malloc(sizeof(char) * MAX);

  fgets(str, MAX - 1, stdin);
  int len = strlen(str);

  printf("%s\n", URLify(str, len));

  free(str);
  return 0;
}

char *URLify(char *str, int len)
{
  int i, count = 0, end;
  for(i = len - 2; str[i] == ' '; i--);

  end = i;
  while(i > 0)
  {
    if(str[--i] == ' ')
    {
      count++;
    }
  }

  i = end;
  while(i)
  {
    if(str[i] != ' ')
    {
      str[i+count*2] = str[i];
    }
    else
    {
      str[i+count*2-2] = '%';
      str[i+count*2-1] = '2';
      str[i+count*2] = '0';
      count--;
    }
    i--;
  }

  return str;
}
