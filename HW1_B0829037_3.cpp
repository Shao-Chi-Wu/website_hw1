#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int main(){
    int **d_array_1;
    int x;
    int max=0;
    char**d_array_2;
    cin>>x;
    //宣告 2 dynamic arrays
    d_array_1=new int*[x+1];     //int宣告的存字串的長度和空白的位置
    d_array_2=new char*[x+1];   //char宣告的存字串
    for(int i=0;i<x+1;i++)
    {
        d_array_1[i]=new int[2];
    }
    //input string 
    //getline會佔掉一個位子 所以x+1
    string name;
    for(int i=0;i<x+1;i++)
    {
        getline(cin,name);
        int length=name.length();
        d_array_1[i][0]=length;        //[i][0]存字串總長度
        for(int j=0;j<length;j++)
        {
            if(name[j]==' ')
            {
                d_array_1[i][1]=j;     //[i][1]存空格是在第幾格
                if(max<j)
                {
                    max=j;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        //將字串存入 d_array_2
        d_array_2[i]=new char[length];     
        for(int k=0;k<length;k++)
        {
            d_array_2[i][k]=name[k];
        }
    }
    cout << "----------------" << endl;
    //output
    for(int i=1;i<x+1;i++)
    {
        for(int j=0;j<max-d_array_1[i][1];j++)   //判斷跟最長的字串中 空白的位置相差多少 補空白在前面
        {
            cout<<" ";
        }
        for(int k=0;k<d_array_1[i][0];k++)       //output string 
        {
            cout<<d_array_2[i][k];
        }
        cout<<endl;
    }
    //清空二維陣列
    for(int i=0;i<x+1;i++)
    {
        delete [] d_array_1[i];
        delete [] d_array_2[i];
    }
    delete [] d_array_1;
    delete [] d_array_2;
}