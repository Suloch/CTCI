
/*
Question:
check whether the characters in a string are unique or not

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int checkUnique(char *, int);

int main()
{
  char *str = malloc(MAX * sizeof(char));
  fgets(str, MAX, stdin);
  if(checkUnique(str, strlen(str)))
  {
    printf("Unique\n" );
  }
  else
  {
    printf("No\n" );
  }
  free(str);
  return 0;
}


int checkUnique(char *str, int len)
{
  unsigned int A[4];
  int i, j, k;

  for(j = 0; j < 4; j++)
  {
    A[j] = 0;
  }

  for(i = 0; i < len; i++)
  {
    j = str[i] / 32;
    k = str[i] % 32;
    if((A[j] & (1 << k)) != 0)
    {
      return 0;
    }
    else
    {
      A[j] = A[j] | (1 << k);
    }
  }
  return 1;
}
