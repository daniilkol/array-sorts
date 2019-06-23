#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void sort(char** a, int n, int (*p)(const char*,const char*))
{
    int i,j,k;
    char* x;
    for (j=0;j<n;j++)
    {
        k=j;
        for (i=j;i<n;i++)
            if ((*p)(a[i],a[k]))
                k=i;

        x=a[j];
        a[j]=a[k];
        a[k]=x;

    }

}
