#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct deadline
{
    int zile;
    int puncte;
};
int comp( const void *a, const void *b)
{
    struct deadline al=*(struct deadline*)a;
    struct deadline bl=*(struct deadline*)b;
    int s=bl.puncte-al.puncte;
    if(s) return s;
        else    return al.zile-bl.zile;
}
int main()
{
    int n,i,s=0;
    FILE *f=fopen("date.in","r");
    FILE *g=fopen("date.out","w");
   printf("n: ");
   scanf("%d",&n);
    struct deadline v[n];
    for (i=0;i<n;i++)
    fscanf(f,"%d %d",&v[i].zile,&v[i].puncte);
    qsort(v,n,sizeof(struct deadline),comp);
    for(i=0;i<5;i++)
        s=s+v[i].puncte;
    fprintf(g,"%d",s);
    fclose(f);
    fclose(g);
    return 0;
}
