#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include "read.c"
#include "read.h"
#include "sort.c"
#include "sort.h"
int compare (const char* a,const char* b);
int compare (const char* a,const char* b)
{
    return (strcmp(a,b)>=0);
}
int main(void)
{
   char** a;
   int n,i,k;
   double t;
   const char *name="a.txt";
   int (*ptr)(const char*,const char*);
   ptr=&compare;
   printf("Input lenght: ");
   if(scanf("%d",&n)!=1)
   {
       printf("Cannot read\n");
       return 1;
   }
   if(!(a=(char**)malloc(n*sizeof(char*))))
   {
       printf("Not enough memory\n");
       return 2;
   }
   k=read_array(name,a,n);
   if(k<0)
   {
       switch(k)
       {
           case -1: printf("Cannot open %s\n",name); break;
           case -2: printf("Cannot read %s\n",name); break;
           case -3: printf("Cannot allocate string\n"); break;
           default: printf("Unknown error\n"); break;
       }
       free(a);
       return 2;
   }
   printf("Strings before sort:\n");
   print_array(a,n);
   t=clock();
   sort(a,n,ptr);
   t=(clock()-t)/CLOCKS_PER_SEC;
   printf("Strings after sort:\n");
   print_array(a,n);
   printf("Elapsed time:%.2lf\n",t);
   for (i=0;i<n;i++)
   free (a[i]);
   free(a);
   return 0;
}
