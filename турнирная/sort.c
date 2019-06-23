#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <math.h>
void sort(char** a, int n, int (*p)(const char*,const char*))
{
   int i,j,k;
   char* x;
   char* ix ;
   for (i=1;i<n;i++)
    {
        x=a[i];
        j=i;
        k=(j-1)/2;
        while (j>0&&(*p)(a[k],x))
        {
            a[j]=a[k];
            j=k;
            k=(j-1)/2;
        }
        a[j]=x;
    }
    for (i=n-1;i>0;i--)
    {
        ix=a[i] ;
        a[i]=a[0] ;
        k=0;
        if (i==1)
            j=-1 ;
        else
            j=1 ;
        if (i>2&&(*p)(a[1],a[2]))
            j=2 ;
        while (j>=0&&(*p)(ix,a[j]))
        {
            a[k]=a[j];
            k=j;
            j=2*k+1;
            if (j+1<=i-1&&(*p)(a[j],a[j+1]))
                j++;
            if (j>i-1)
                j=-1 ;
        }
        a[k]=ix;
    }
}
