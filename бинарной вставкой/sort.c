#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
int fun(char** a,int n,const char* x,int (*p)(const char*,const char*));
int fun(char** a,int n,const char* x,int (*p)(const char*,const char*))
{
    int s,l=0,r=n;
    while (l!=r)
      {
       s=(l+r)/2;
    if ((*p)(a[s],x))
        l=s+1;
    else r=s;
      }
return l;
}
void sort(char** a, int n, int (*p)(const char*,const char*))
{
  int i,j,k;
  char* x;
  for (i=1;i<n;i++)
  {   x=a[i];
      k=fun(a,i,a[i],p);
      for (j=i;j>k;j--)
      a[j]=a[j-1];
      a[k]=x;
  }
}
