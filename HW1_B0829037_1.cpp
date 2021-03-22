#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    //宣告二維陣列
    char** array;
    array=new char*[x];
    for(int i=0;i<x;i++)
    {
        array[i]=new char[y];
    }
    //input string
    cin.ignore();
    for(int i=0;i<x;i++)
    {
        cin.getline(array[i],100);
    }
    //Bubble sort
    char *temp;
    temp=new char;
    for(int j=0;j<x-1;j++)
    {
        for(int i=0;i<x-1-j;i++)
        {
            if(array[i][0]<array[i+1][0])
            {   
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp; 
            }
        }
    }
    cout << "----------------" << endl;
    for(int i=0;i<x;i++)
    {
        cout<<array[i]<<endl;
    }
    //清空二維陣列
    for(int i=0;i<x;i++)
    {
        delete[] array[i];
    }
    delete[] array;
}