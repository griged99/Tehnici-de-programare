#include<iostream>
#include<ctime>
#include<cstdlib>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n, v[10];

int solutie(int k) {
    if (k == n) return 1;
    else return 0;
}

void tiparire(int k) {
    int i;
    for (i = 1; i <= k; i++)
        g << v[i] << " ";
    g << endl;
}

int verifica(int k) {
    int p = 1, i;
    for (i = 1; i <= k - 1; i++)
        if (v[k] == v[i]) p = 0;
    for (i = 1; i <= k - 1; i++)
        if (abs((v[i] - v[i + 1])) < 2) p = 0;
    return p;
}

void back(int k) {
    int i;
    for (i = 1; i <= n; i++) {
        v[k] = i;
        if (verifica(k))
            if (solutie(k))
                tiparire(k);
            else back(k + 1);
    }
}

int main() {
    srand(time(0));
    n = rand() % 9 + 1;
    while (n < 4) {
        n = rand() % 10 + 1;
    }
    g << n;
    back(1);
}
