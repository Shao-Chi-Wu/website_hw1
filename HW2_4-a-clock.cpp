#include<iostream>
#include<ctime>
using namespace std;
int main(){
    int **a, **b, **c;
    int m = 10000, n = 3000;
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
        for (int j = 0; j < n;j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    y = clock();
    cout << double(y - x) / CLOCKS_PER_SEC << endl;
}