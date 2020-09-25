#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b) {
    int x = *(int*) a;
    int y = *(int*) b;
    if(x>y)
        return 1;
    else if (x<y)return -1;
    else return 0;
}

int main() {
    int n, s, i;
    FILE *f= fopen("date.in", "r");
    fscanf(f, "%d", &n);
    scanf("%d", &s);
    int v[n];
    for (i = 0; i < n; i++) {
        int sec, min;
        fscanf(f, "%d%d", &min, &sec);
        v[i] = min*60+sec;
    }
    qsort(v, n, sizeof(int), comp);
    int k=0;
    for(i = 0; i < n; i++)
    {
        if(s < v[i])
            break;
        s=s-v[i];
        k++;
    }
    printf("%d",k);
    return 0;
}
