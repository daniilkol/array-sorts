#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void sort(char** a, int n, int (*p)(const char*,const char*))
{
    int i,j;
    char* x;
   for (j=n;j>1;j--)
    {
        for (i=0;i<j-1;i++)
            if ((*p)(a[i+1],a[i]))
        {
              x=a[i];
              a[i]=a[i+1];
              a[i+1]=x;

        }
    }
}
