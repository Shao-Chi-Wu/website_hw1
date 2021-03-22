#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Quadratic{
    private:
        float data_a, data_b, data_c;
    public:
        Quadratic();
        Quadratic(float a, float b, float c);
        float getdata_a();
        float getdata_b();
        float getdata_c();
        float total_value(float x);
        friend istream &operator>>(istream &inputStream, Quadratic &s);
        friend ostream &operator<<(ostream &outputStream, Quadratic &s);
};
Quadratic::Quadratic()
{
    data_a = 0;
    data_b = 0;
    data_c = 0;
}
Quadratic::Quadratic(float a, float b, float c)
{
    data_a = a;
    data_b = b;
    data_c = c;
}
float Quadratic::getdata_a()
{
    return data_a;
}
float Quadratic::getdata_b()
{
    return data_b;
}
float Quadratic::getdata_c()
{
    return data_c;
}
float Quadratic::total_value(float x)
{
    return (data_a * x * x + data_b * x + data_c);
}
Quadratic operator +(Quadratic&a,Quadratic&b)
{
    return Quadratic(a.getdata_a() + b.getdata_a(),a.getdata_b() + b.getdata_b(),a.getdata_c() + b.getdata_c());
}
istream &operator>>(istream &inputStream, Quadratic &s)
{
    inputStream >> s.data_a >> s.data_b >> s.data_c;
    return inputStream;
}
ostream &operator<<(ostream &outputStream, Quadratic &s)
{
    if((s.data_b>0)&&(s.data_c<0))
        outputStream << s.data_a << "x^2"<< "+" << s.data_b << "x" << s.data_c << endl;
    else if((s.data_b<0)&&(s.data_c<0))
        outputStream << s.data_a << "x^2" << s.data_b << "x" << s.data_c << endl;
    else if((s.data_b<0)&&(s.data_c>0))
        outputStream << s.data_a << "x^2" << s.data_b << "x" << "+" << s.data_c << endl;
    else 
        outputStream << s.data_a << "x^2" << "+" << s.data_b << "x" << "+ "<< s.data_c << endl;
    return outputStream;
}
int main(){
    float value_x;
    Quadratic first, second, third;
    cout << "enter your equation coefficients" << endl;
    cin >> first  ;
    cin >> second  ;
    cout << "first equation=" << first << endl;
    cout << "second equation=" << second << endl;
    third = first + second;
    cout << "third equation=" << third << endl;
    cout << "value_x=";
    cin >> value_x;
    cout << third.total_value(value_x) << endl;
}