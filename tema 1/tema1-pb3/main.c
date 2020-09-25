#include <stdio.h>
#include <stdlib.h>

struct mancare {
    int tip, minute, secunde, pret, nr_portii;
    float profit;
};

void transformare_secunde(struct mancare *x, int n) {
    int i;
    for (i = 0; i < n; i++)
        x[i].secunde += 60 * x[i].minute;
}

void timp_preparare(struct mancare *x, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 1; j < x[i].nr_portii; j++)
            x[i].secunde += x[i].secunde / 2;
    }
}

void calculare_profit(struct mancare *x, int n) {
    int i;
    for (i = 0; i < n; i++) {
        x[i].profit = x[i].pret * x[i].nr_portii;
        x[i].profit /= x[i].secunde;
    }
}

int comparator(const void *a, const void *b) {
    struct mancare x = *(struct mancare *) a;
    struct mancare y = *(struct mancare *) b;
    if (x.profit < y.profit)
        return 1;
    return -1;
}


int main() {
    struct mancare m[100];
    int n, i;
    FILE *f = fopen("date.in", "r");
    fscanf(f, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(f, "%d%d%d%d%d", &m[i].tip, &m[i].minute, &m[i].secunde, &m[i].pret, &m[i].nr_portii);
        m[i].profit = 0;
    }
    transformare_secunde(m, n);
    timp_preparare(m, n);
    calculare_profit(m,n);
    qsort(m, n, sizeof(struct mancare), (*comparator));
    printf("Ordinea optima este: \n");
    for (i = 0; i < n; i++)
        printf("Id: %d Secunde: %d Pret: %d Numar portii: %d Profit:%f \n", m[i].tip, m[i].secunde, m[i].pret,
               m[i].nr_portii, m[i].profit);
    fclose(f);
    return 0;
}
