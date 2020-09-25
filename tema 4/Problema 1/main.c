    #include <stdio.h>
    #include <stdlib.h>
    int n, **v, *lmax, *succ, m, n, pmax;
    FILE *g;

    void lis(int column)
        {int i, j;

        for(i = n-1; i >= 0; i--)
            {lmax[i]=1;
            succ[i] = -1;

            for(j = i+1; j < n; j++)
                if((v[i][column] <= v[j][column]) && (1+lmax[j]>lmax[i]))
                   {lmax[i] = 1+lmax[j];
                    succ[i] = j;
                   }
            }

        pmax=0;

        for(i = 0; i < n; i++)
            if(lmax[i]>lmax[pmax]) pmax = i;

        fprintf(g, "Cel mai mare sir crescator de pe coloana %d este: \n", column);

        for(i=pmax; i!=-1; i=succ[i])
            fprintf(g, "%d ", v[i][column]);
            fprintf(g, "\n\n\n");

        }

    int main()
    {int i, j;
    FILE *f = fopen("date.in", "r");

    fscanf(f, "%d %d", &n, &m);

    v = (int**)malloc(n*sizeof(int*));
    lmax = (int*)malloc(n*sizeof(int));
    succ = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n; i++)
        v[i] = (int*)malloc(n*sizeof(int));


    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            fscanf(f, "%d", &v[i][j]);

    fclose(f);

    g = fopen("date.out", "w");

    for(j = 0; j < m; j++)
        lis(j);

     fclose(g);

     free(lmax);
     free(succ);
     for(i = 0; i < n; i++)
            free(v[i]);
     free(v);
        return 0;
    }
