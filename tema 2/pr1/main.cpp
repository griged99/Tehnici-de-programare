#include<iostream>
#include<string>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int solutie(int k) {
    if (k == 3) return 1;
    else return 0;
}

void tiparire(int n, string *v) {
    int i;
    for (i = 1; i <= n; i++)
        g << v[i] << " ";
    g << endl;
}

int verifica(int k, string *v) {
    int p = 1, i;
    for (i = 1; i <= k - 1; i++)
        if (v[k] == v[i]) p = 0;
    return p;
}

string z[10];

void back(int k, string *v, int n) {

    int i;
    for (i = 0; i < n; i++) {
        z[k] = v[i];
        if (verifica(k, z))
            if (solutie(k))
                tiparire(k, z);
            else back(k + 1, v, n);
    }
}

int main() {
    int n;
    f >> n;
    string a[n + 1];
    for (int i = 0; i < n; i++)
        f >> a[i];

    back(1, a, n);
}
