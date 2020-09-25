    #include <stdio.h>
    #include <stdlib.h>
    int n, *v, *lmax, *succ,pmax;
    FILE *g;

    void lis()
        {int i, j, afisare[100], k=0 ,max =0, p = 0;

        for(i = n-1; i >= 0; i--)
            {lmax[i]=1;
            succ[i] = -1;

            for(j = i+1; j < n; j++)
                if((v[i] >= v[j]) && (1+lmax[j]>lmax[i]))
                   {lmax[i] = 1+lmax[j];
                    succ[i] = j;
                   }
            }

        for(i=0;i<n;i++)
            if(lmax[i]>lmax[pmax]){ pmax=i; max=lmax[pmax];}
                fprintf(g,"Nr min de copaci ca trebuie taiati este %d \n",n-max);

    fprintf(g,"Pozitiilor copacilor ce trebuiesc taiati sunt urmatoarele: ");
    for(i=pmax;i!=-1;i=succ[i]){
        for(j=k;j<i;j++)
            fprintf(g,"%d ",j);
        k=i+1;
    }
        }


    int main()
    {int i, j;
    FILE *f = fopen("date.in", "r");

    fscanf(f, "%d", &n);

    v = (int*)malloc(n*sizeof(int));
    lmax = (int*)malloc(n*sizeof(int));
    succ = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n; i++)
            fscanf(f, "%d", &v[i]);


    fclose(f);

    g = fopen("date.out", "w");

    lis();

     fclose(g);

     free(lmax);
     free(succ);
     free(v);

        return 0;
    }
