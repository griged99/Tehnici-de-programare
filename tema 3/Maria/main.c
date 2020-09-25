#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int caut(int v[],int dr,int st)
{
    int mij = (st+dr)/2;
    if(mij == 0 && v[mij] == 1)
        return -1;
    else if(v[mij] == 1 && v[mij-1] == 0)
        return mij-1;
    else if(v[mij] == 0 && v[mij+1] == 1)
        return mij;
    else if(v[mij] == 1)
        caut(v, dr, mij);
    else if(v[mij] == 0)
        caut(v, mij+1, st);
}
int main()
{
    FILE *f=fopen("date.in","r");
    FILE *g=fopen("date.out","w");
    int n,k;
    fscanf(f,"%d",&n);
        int r,i,v[n];
    srand(time(NULL));
    r= rand() % n;
    for(i=0;i<n;i++)
    {
        if(i<r) v[i]=0;
        else v[i]=1;
    }

    k=caut(v,0,n-1);
    fprintf(g,"%d %d\n",r, k);
    for(i=0;i<=k;i++)
    {
        fprintf(g,"%d ",i);
    }
}
