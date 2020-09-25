#include <stdio.h>
#include <stdlib.h>
int cmmdc(int v[],int inf,int sup)
{
   int a,b,m,r;
   if(inf==sup)
    return v[inf];
   else
   {
       m=(inf+sup)/2;
       a=cmmdc(v,inf,m);
       b=cmmdc(v,m+1,sup);
       if (b==1)
        return -1;
       else
            while(b)
            {
                r=a%b;
                a=b;
                b=r;
                if(b==1)
                    return -1;
            }
       return a;
   }

}
int main()
{
    int n,i,k;
    FILE *f= fopen("date.in", "r");
    FILE *g= fopen("date.out","w");
    fscanf(f, "%d", &n);
    int v[n];
    for (i=0;i<n;i++)
        fscanf(f,"%d",&v[i]);
    k=cmmdc(v,0,n-1);
    fprintf(g,"%d",k);
    return 0;


}
