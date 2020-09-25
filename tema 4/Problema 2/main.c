    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {int n, i, j, v[100][100], smax[100][100], max = -1, maxim = 0, k;

    FILE *f = fopen("date.in", "r");

    fscanf(f, "%d", &n);


    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            fscanf(f, "%d", &v[i][j]);

    fclose(f);

    FILE *g = fopen("date.out", "w");

    fprintf(g, "Matricea de testare este urmatoarea: \n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            {fprintf(g," %d ",v[i][j]);
            if( j == n-1) fprintf(g, "\n");}
            fprintf(g, "\n\n\n\n\n");

    for(j = 0; j < n; j++)
        smax[n-1][j] = v[n-1][j];



    for(i=n-2; i>=1; i--)
        for(j=0; j < n; j++)
            {smax[i][j]=v[i][j] +(smax[i+1][j]>smax[i+1][j+1]? smax[i+1][j]:smax[i+1][j+1]);

            if( (i == 1) && (v[i][j] > max)) max = v[i][j];
            }


    for(i = 0; i < n; i++)
    if(v[1][i] == max) fprintf(g, "Pionul de pe prima linie poate fi asezat pe pozitia v[%d][%d] sau v[%d][%d]\n", 0, i-1, 0, i);

    for(i = 1; i < n; i++)
        {max = -1;

        for(j = 0; j < n; j++ )
            if(v[i][j] > max) max = v[i][j];


    fprintf(g, "Pasi pe care ii urmeaza:");

         for(j = 0; j < n; j++ )
            {if(v[i][j] == max) {fprintf(g, " i=%d j=%d ", i, j);
                    for(k = j+1; k<n; k++)
                        if(v[i][k] == max) fprintf(g, " sau  i=%d j=%d", i,k);
                    fprintf(g, "\n");
                    break;}
            }



        }

    fclose(g);




        return 0;
    }



