#include <stdio.h>
#include <stdlib.h>

int pivot(int v[],int st,int dr)
{
    int i=st,j=dr,aux,k=1;
    while(i<j)
    {
        if(v[i]>v[j])
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            k=3-k;
        }
        if(k==1) j--;
        else i++;
    }
    return i;
}
void QuickSort(int v[],int st,int dr)
{
    int p;
    if(st<dr)
    {
        p=pivot(v,st,dr);
        QuickSort(v,st,p-1);
        QuickSort(v,p+1,dr);
    }
}
int main()
{
    FILE *f=fopen("date.in","r");
    FILE *g=fopen("date.out","w");
    int n;
    fscanf(f,"%d",&n);
    int v[n],i;
    for(i=0;i<n;i++)
        fscanf(f,"%d",&v[i]);
   QuickSort(v,0,n-1);
   for (i=0;i<n;i++)
    fprintf(g,"%d ",v[i]);
    return 0;
}
