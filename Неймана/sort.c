#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void fun(char** a,int n,char** b,int m,char** c,int (*p)(const char*,const char*));
void fun(char** a,int n,char** b,int m,char** c,int (*p)(const char*,const char*))
{
    int i=0,j=0,k=0;
    while((i<n)&&(j<m))
    {
        if ((*p)(a[i],b[j]))
            {
                c[k]=a[i];
                i++;
            }
            else
            {
                c[k]=b[j];
                j++;
            }
            k++;
    }
    if (i==n)
    while (j<m)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    else
        while (i<n)
    {
        c[k]=a[i];
        k++;
        i++;
    }
}
void sort(char** a,char** b, int n, int (*p)(const char*,const char*))
{
  char** c;
  char** a_original=a;
  int i,j,k=1;

  while (k<=n-1)
  {
    for (i=0;i<n;i=i+2*k)
      if (i+2*k<=n)
	fun(a+i,k,a+i+k,k,b+i,p);
      else
      {
	for (j=i;j<n;j++)
	  b[j]=a[j];
	break;
      }
    c=a;
    a=b;
    b=c;
    k=2*k;
  }
  k=k/2;
  fun(a,k,a+k,n-k,b,p);
  if (a==a_original)
    for (i=0;i<n;i++)
      a[i]=b[i];
}
