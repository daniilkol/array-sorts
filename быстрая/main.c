#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int read_array (const char *name, double *a,int maxn);
void init_array (double *a, int n, int key);
void print_array (double *a,int n);
void quicksort (double *a, int left,int right);
void Swap( double *a, double *b )
{
  double tmp;
  tmp = *a, *a = *b, *b = tmp;
}
int read_array (const char *name, double *a,int maxn)
{
    FILE *fp;
    int i;
    if(!(fp=fopen(name,"r")))
        return -1;
   for(i=0;i<maxn; i++)
    {
        if(fscanf(fp,"%lf", a+i)!=1)
        {
            if(!feof(fp))
            {
                fclose(fp);
                return -2;
            }
        }

        }
        fclose(fp);
        return i;
}
void init_array (double *a, int n, int key)
{
    int i;
    srand(key);
    for (i=0;i<n;i++)
        a[i]=rand();
}
#define NMAX 20
void print_array (double *a,int n)
{
    int i;
    int m=(n >NMAX ? NMAX:n);
    for (i=0;i<m;i++)
    printf("%lf\n",a[i]);
}
void quicksort (double *a, int left,int right)
{   int i=0, j=right;
    int tmp;
    int pivot = a[(left + right) / 2];


    /* partition */
    while (i <= j) {
        while (a[i] < pivot)
        i++;
        while (a[j] > pivot)
        j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
    quicksort(a, left, j);
    if (i < right)
    quicksort(a, i, right);

}
int main (void)
{
    const char *name="a.txt";
    int n,key;
    double *a;
    int res;
    printf ("Input n and key: ");
    if(scanf("%d%d",&n,&key)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    if(!(a=(double*)malloc(n*sizeof(double))))
       {
           printf("Not enough memory!\n");
           return 2;
       }
       if (key==0)
       {
         res=read_array(name,a,n);
            if(res<0)
            {
                switch (res)
                {
                    case -1:
                        printf("Cannot open%s\n",name);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name);
                        break;
                    default:
                        printf("Unknown error%s\n",name);
                        break;
                }
                free(a);
                return 3;
            }
            n=res;
       }
       else init_array(a,n,key);
       printf("Array a: \n");
       print_array(a,n);
       quicksort(a,0,n-1);
       printf("Array after sort: \n");
       print_array(a,n);
       free(a);
       return 0;
}
