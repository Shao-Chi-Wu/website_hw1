#include<iostream>
#include<ctime>
using namespace std;
int main(){
    int **a, **b, **c;
    int m=10000, n=2800, p=100;
    a = new int *[m];
    b = new int *[m];
    c = new int *[m];
    for (int i = 0; i < m;i++)
    {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];
    }
    clock_t x, y;
    x = clock();
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < p;j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    y = clock();
    cout << double(y - x) / CLOCKS_PER_SEC << endl;
}