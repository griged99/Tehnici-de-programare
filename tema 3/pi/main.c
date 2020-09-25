#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MergeSort(int v[],int inf, int sup)
{
   int mid;int n=sup;
   if(inf<sup)
   {
       mid=(inf+sup)/2;
       MergeSort(v,inf,mid);
       MergeSort(v,mid+1,sup);
       interclasare(v,inf,mid,sup,n);
   }
   return 0;
}
void interclasare(int v[],int inf,int mid,int sup,int n )
{
	int a[n];
	int i = inf;
	int j = mid +1 ;
	int k = inf ;

	while( (i <= mid) && (j <=sup) )
	{
		if(v[i] <= v[j])
			a[k++] = v[i++] ;
		else
			a[k++] = v[j++] ;
	}
	while( i <= mid )
		a[k++]=v[i++];

	while( j <= sup )
		a[k++]=v[j++];

	for(i= inf; i <= sup ; i++)
		v[i]=a[i];

}

int main()
{
    FILE *g=fopen("date.out","w");
   FILE *f=fopen("date.in","r");
   int n, k,i ;
   fscanf(f,"%d",&n);
    int v[n];
    srand(time(NULL));
    k= rand() % (n/2);
    printf("k=%d ",k);
   for(i=0;i<n;i++)
    v[i]=rand();
    for(i=0;i<n;i++)
        fprintf(g,"%d ",v[i]);
    fprintf(g,"\n");
    MergeSort(v,0,k-1);
    for(i=0;i<k;i++)
        fprintf(g,"%d ",v[i]);

}
