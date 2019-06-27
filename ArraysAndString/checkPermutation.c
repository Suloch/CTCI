
/*
Question:
check whether a string is permutation of other string
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int checkPermutation(char*, char*, int, int);

int main()
{
  char *str1 = malloc(sizeof(char) * MAX);
  char *str2 = malloc(sizeof(char) * MAX);

  fgets(str1, MAX-1, stdin);
  fgets(str2, MAX-1, stdin);

  if(checkPermutation(str1, str2, strlen(str1), strlen(str2)))
  {
    printf("Permutation\n");
  }
  else
  {
    printf("No\n");
  }
  free(str1);
  free(str2);
  return 0;
}



int checkPermutation(char *str1, char *str2, int len1, int len2)
{
  int frequency[128];

  int i;

  for(i = 0; i < 128; i++)
  {
    frequency[i] = 0;
  }

  if(len1 != len2)
  {
    return 0;
  }

  for(i = 0; i < len1; i++)
  {
    frequency[str1[i]]++;
    frequency[str2[i]]--;
  }

  for(i = 0; i < 128; i++)
  {
    if(frequency[i] != 0)
    {
      return 0;
    }
  }

  return 1;
}
