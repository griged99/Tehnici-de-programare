    #include <stdio.h>
    #include <stdlib.h>
    int n, *v, *lmax, *succ,pmax;
    FILE *g;

    void lis()
        {int i, j, afisare[100], k = -1, p = 0;

        for(i = n-1; i >= 0; i--)
            {lmax[i]=1;
            succ[i] = -1;

            for(j = i+1; j < n; j++)
                if((v[i] <= v[j]) && (1+lmax[j]>lmax[i]))
                   {lmax[i] = 1+lmax[j];
                    succ[i] = j;
                   }
            }

        for(i=0;i<n;){
            if(succ[i]==-1) i++;
            else{fprintf(g, "Un subsir crescator este: \n");
                for(j=i;j!=-1;j=succ[j])
                    fprintf(g,"%d ",v[j]);
                fprintf(g,"\n");
                i++;
                }
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
