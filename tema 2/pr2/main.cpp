#include<fstream>
#include<string>
#include<iostream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int x[50],k,valid,n,m;
int dim[50];
string cul[50];

void citire()
{

    f>>n;

    f>>m;
    for(int i=1;i<=n;i++)
    {

        f>>dim[i];
        f>>cul[i];
    }

}

void posibil(int k,int &valid)
{
    valid=1;
    for (int i=1;i<k;i++)
        if(x[i]==x[k])
            valid=0;
    if(k>1)
        if(cul[x[k-1]] == cul[x[k]])
            valid=0;
}

int solutie(int k)
{
    if(k==m)
        return 1;
    else
        return 0;
}

void afisare(int k)
{
    for(int i=1;i<=k;i++)
        g<<dim[x[i]]<<" "<<cul[x[i]]<<" ";
    g<<endl;
}

void back()
{
    k=1;
    x[k]=0;
    while(k>0)
    {
        valid=0;
        while(!valid && x[k]<n)
        {
            x[k]=x[k]+1;
            posibil(k,valid);
        }
        if(!valid)
            k--;
        else if(solutie(k))
            afisare(k);
        else
        {
            k++;
            x[k]=0;
        }
    }
}

int main()
{
    citire();
    back();
    afisare(k);

}
