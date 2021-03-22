#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class MatrixTerm
{
    friend class SparseMatrix;
    private:
        int row, col, value;
};

class SparseMatrix
{
    public:
        SparseMatrix(int data_rows,int data_cols);
        SparseMatrix(int terms);
        SparseMatrix Transpose();
        void output();
    private:
        int rows,cols,terms,capacity;
        MatrixTerm *smArray;
};
SparseMatrix::SparseMatrix(int data_rows,int data_cols)     //做triple
{
    int **Matrix;
    int count = 0;
    Matrix = new int *[data_rows];                          //用題目給的矩陣的rows&cols創一個陣列，為了cin>>題目的陣列
    for (int i = 0; i < data_rows;i++)
    {
        Matrix[i] = new int[data_cols];
    }
    for (int i = 0; i < data_rows;i++)                      //cin>>矩陣
    {
        for (int j = 0; j < data_cols;j++)
        {
            cin >> Matrix[i][j];
            if(Matrix[i][j]!=0)
            {
                count++;                                    //count代表在矩陣中有幾個為非0的值
            }
        }
    }
    rows = count;
    cols = count;
    terms = count;
    capacity = count;
    smArray = new MatrixTerm[count];                    //建立一個大小是非零值數量的陣列
    int t = 0;
    for (int i = 0; i < data_rows;i++)
    {
        for (int j = 0; j < data_cols;j++)
        {
            if(Matrix[i][j]!=0)                         //判斷矩陣中不是0的位置
            {
                smArray[t].row = i;                     //存row的位置是多少
                smArray[t].col = j;                     //存col的位置是多少
                smArray[t].value = Matrix[i][j];        //存value的值是多少
                t++;                                    //t到最後的次數會跟count一樣
            }
        }
    }
}
void SparseMatrix::output()
{
    for (int i = 0; i < capacity;i++)
    {
        cout << smArray[i].row << "    " << smArray[i].col << "    " << smArray[i].value << endl;
    }
}
SparseMatrix::SparseMatrix(int t)
{
    rows = t;
    cols = t;
    terms = t;
    capacity = t;
    smArray = new MatrixTerm[t];
}
SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(terms);                           //宣告一個物件b
    if(terms>0)
    {
        int **rowSize;
        rowSize= new int*[2];
        for (int i = 0; i < 2;i++)
        {
            rowSize[i] = new int[cols];
        }
        fill(rowSize[0], rowSize[0] + cols, 0);     //初始化，計數的時候比較不會出錯
        for (int i = 0; i < terms;i++)
        {
            rowSize[0][smArray[i].col]++;
        }
        rowSize[1][0]=0;
        for (int i = 1; i < cols;i++)
        {
            rowSize[1][i] = rowSize[1][i - 1] + rowSize[0][i - 1];
        }
        for (int i = 0; i < terms;i++)              //做rowStart
        {
            int j = rowSize[1][smArray[i].col];     //讀取col，然後從第幾個開始換
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowSize[1][smArray[i].col]++;           //如果又讀到一樣的數字，就從上一個開始的位置加一繼續
        }
        for (int i = 0; i < 2;i++)
        {
            delete[] rowSize[i];
        }
        delete[] rowSize;
    }
    return b;
}

int main(){
    int r, c;
    cin >> r >> c;
    SparseMatrix p(r, c);
    cout <<"row " <<"col "<<"value"<< endl;
    p.output();
    cout << "-------------------------" << endl;
    cout <<"row " <<"col "<<"value"<< endl;
    p= p.Transpose();
    p.output();
}