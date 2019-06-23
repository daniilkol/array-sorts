#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void sort(char** a, int n, int (*p)(const char*,const char*))
{
  int i,j,k;
  char* x;
  for (i=1;i<n;i++)
  {
    x=a[i];
    for (j=0;j<i-1;j++)
      if (((*p)(a[i],a[j]))&&((*p)(a[j+1],a[i])))
      {
	      k=j+1;
	      break;
      }
    if (j==i-1)
      if ((*p)(a[0],a[i]))
	k=0;
      else
	k=i;
    for (j=i;j>k;j--)
      a[j]=a[j-1];
    a[k]=x;
  }
}
