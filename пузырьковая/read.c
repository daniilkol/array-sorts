#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#define LEN 1234
#define NMAX 20
void print_array ( char** a,int n)
{
    int i;
    int m=(n>NMAX?NMAX:n);
    for (i=0;i<m;i++)
        printf("%s\n",a[i]);
}
int read_array (const char *name, char** a,int n)
{
    int i,j;
    FILE *fp;
    char buf[LEN];
    if(!(fp=fopen(name,"r")))
        return -1;
    for (i=0;i<n;i++)
    {
        if(!fgets(buf,LEN,fp))
        {
            if(feof(fp))
            {
                fclose(fp);
                return -2;
            }
            fclose(fp);
            return i;
        }
        for (j=0;buf[j];j++)
            if (buf[j]=='\n')
        {
            buf[j]=0;
            break;
        }
        a[i]=(char*)malloc((j+1)*sizeof(char));
        if(!a[i])
        {
            fclose(fp);
            return -3;
        }
        strcpy(a[i],buf);
    }
    fclose(fp);
    return i;
}
