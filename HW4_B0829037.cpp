#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

class node 
{
    friend class linkedlist;
    public:
        node *link;
        int coef, exp;
};
class linkedlist
{
    public:
        linkedlist(int n);                                      //初始化
        void insertNewNode(int in_coef,int in_exp);             //新增node
        void output();
        linkedlist mul(linkedlist p2);                                //相乘
        linkedlist add(linkedlist p2);
    private:
        node *first;
        node *last;
        int term;
};
linkedlist::linkedlist(int n)                                   //初始化
{
    first = new node;
    last = new node;
    first->link = NULL; 
    last->link = NULL;
    term = n;
}
void linkedlist::insertNewNode(int in_coef,int in_exp)          //新增node
{
    node *a = new node;             //create newnode a to save coef and exp
    node *b = new node;
    a->coef = in_coef;
    a->exp = in_exp;
    a->link = NULL;
    if(first->link==NULL)
    {
        first->link = a;            //first指向a
    }
    else
    {
        b = last->link;             //b->a->NULL
        b->link = a;                //b指向a
    }
    last->link = a;
}
void linkedlist::output()                                       //輸出
{
    node *p = new node;
    p = first->link;
    while(p->link!=NULL)
    {
        cout << p->coef << "x^" << p->exp;
        p = p->link;
        if(p->link==NULL)
        {
            cout << "+" << p->coef << "x^" << p->exp << endl;
            break;
        }
        else
        {
            if(p->link->coef>=0)
            {
                cout << "+";
            }
        }
    }
}
linkedlist linkedlist::mul(linkedlist p2)                       //相乘
{
    linkedlist ans(term * p2.term);
    linkedlist temp1(p2.term * term);
    node *p = new node;
    node *q = new node;
    int co, ex;
    p = first->link;
    q = p2.first->link;
    for (int i = 0; i < term;i++)
    {
        linkedlist temp2(p2.term);          //創一個空間去存node 但還沒有node被建立
        for (int j = 0; j < p2.term;j++)
        {
            co = p->coef * q->coef;
            ex = p->exp + q->exp;
            temp2.insertNewNode(co, ex);    //建立新的node,把co,ex存進去
            if(q->link!=NULL)
            {
                q = q->link;
            }
            else
            {
                break;
            }
        }
        if(i==0)
        {
            temp1 = temp2;
        }
        else
        {
            ans = temp1.add(temp2);
            temp1 = ans;
        }
        if(p->link!=NULL)
        {
            p = p->link;
            q = p2.first->link;
        }
        else
        {
            break;
        }
    }
    return ans;
}
linkedlist linkedlist::add(linkedlist p2)                       //相加
{
    linkedlist final(term + p2.term);
    node *p = new node;
    node *q = new node;
    int co, ex;
    p = first->link;
    q = p2.first->link;
    while(1)
    {
        if(p->exp>q->exp)                       //比較次方大小 p>q
        {
            co = p->coef;
            ex = p->exp;
            final.insertNewNode(co, ex);        //p大,存係數跟次方數到新的node
            if(p->link==NULL)                   //假設現在為p的這個node的link指向NULL
            {
                while(1)                        //代表第一個多項式結束了
                {
                    co = q->coef;               
                    ex = q->exp;
                    final.insertNewNode(co, ex);    //直接把第二個剩下的項式存到新的node
                    if(q->link!=NULL)
                    {
                        q = q->link;                //指向的指標往後移動
                    }
                    else
                    {
                        return final;
                    }
                }
            }
            else                                //不為NULL,P指標往後指
            {
                p = p->link;
            }
        }
        else if(p->exp<q->exp)                  //比較次方大小 q>p
        {
            co = q->coef;
            ex = q->exp;
            final.insertNewNode(co, ex);
            if(q->link==NULL)
            {
                while(1)
                {
                    co = p->coef;
                    ex = p->exp;
                    final.insertNewNode(co, ex);
                    if(p->link!=NULL)
                    {
                        p = p->link;
                    }
                    else
                    {
                        return final;
                    }
                }
            }
            else                                
            {
                q = q->link;
            }
        }
        else                                    //比較次方大小 p=q
        {
            co = p->coef + q->coef;
            ex = p->exp;
            final.insertNewNode(co, ex);
            if(p->link==NULL&&q->link!=NULL)
            {
                q = q->link;
                while(1)
                {
                    co = q->coef;
                    ex = q->exp;
                    final.insertNewNode(co, ex);
                    if(q->link!=NULL)
                    {
                        q = q->link;                
                    }
                    else
                    {
                        return final;
                    }
                }
            }
            else if(p->link!=NULL&&q->link==NULL) 
            {
                p = p->link;
                while(1)
                {
                    co = p->coef;
                    ex = p->exp;
                    final.insertNewNode(co, ex);
                    if(p->link!=NULL)
                    {
                        p = p->link;
                    }
                    else
                    {
                        return final;
                    }
                }
            }
            else if(p->link!=NULL&&q->link!=NULL)
            {
                p = p->link;
                q = q->link;
            }
            else 
            {
                return final;
            }
        }
    }
}

int main(){
    int term1, term2;
    int co, ex;
    clock_t start, end;
    cin >> term1 >> term2;
    linkedlist p1(term1);
    linkedlist p2(term2);
    for (int i = 0; i < term1;i++)
    {
        cin >> co >> ex;
        p1.insertNewNode(co, ex);
    }
    for (int i = 0; i < term2;i++)
    {
        cin >> co >> ex;
        p2.insertNewNode(co, ex);
    }
    cout << "Polynomial1=";
    p1.output();
    cout << "Polynomial2=";
    p2.output();
    start = clock();
    linkedlist p3 = p1.mul(p2);
    end = clock();
    cout << "Polynomial1*Polynomial2=";
    p3.output();
    cout<<float(end-start)/CLOCKS_PER_SEC;
}