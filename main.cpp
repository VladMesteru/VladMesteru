#include<fstream>
#include<iostream>
using namespace  std;

ifstream fin("ghiozdan.in");
ofstream fout("ghiozdan.out");

typedef struct {
                        float greutate;
                        float profit;
                        float eficienta;
                        } obiect;
obiect M[100];
float profit_total;
float G;
int n, m=0;

int read_data()
{
    fin>>n;
    fin>>G;
    for (int i=1;i<=n;i++)
        {
            fin>>M[i].greutate;
            fin>>M[i].profit;
            M[i].eficienta=M[i].profit/M[i].greutate;
        }
        fin.close();
}

int sort_data()
{
    int i,schimbat,aux;
    do
    {
        schimbat = 0;
        for(i = 0; i < n-1; i++)
            if(M[i].eficienta < M[i+1].eficienta)
            {
                aux = M[i].eficienta;
                M[i].eficienta = M[i+1].eficienta;
                M[i+1].eficienta = aux;
                schimbat = 1;
            }
    }while(schimbat);
}

float procent(int i)
{
    int x;
    x=(M[i].greutate-G)/M[i].greutate*100;
    return x;
}

float sweet_greedy()
{
    int i=1;
    float v[n+1], s=0;
    float G_actual=0, G_dif, benefit=0;
    while(i<n && G>0)
    {
        if(M[i].greutate<=G)
        {
            benefit=benefit+M[i].profit;
            G=G-M[i].greutate;
        }
        else
        {
            benefit=benefit+(M[i].greutate-G)/M[i].greutate*100;;
            G=0;
        }
        i++;
        m++;
    }
    return benefit;
}

int main()
{
    read_data();
    sort_data();
    profit_total=sweet_greedy();
    fout<<profit_total<<endl;
    fout<<m;
    fout.close();
}
