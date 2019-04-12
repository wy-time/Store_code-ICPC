#include <iostream>
#include<cmath>
using namespace std;
int weishu(int n);
int isprime(int n);
int main()
{
    int a,b;
    cin>>a>>b;
    int w1,w2;
    int i,j,k,l;
    int temp;
    w1=weishu(a);
    w2=weishu(b);
    if(w1<=1&&w2>=1)
    {
        if(a<=5&&b>=5)
            cout<<5<<endl;
        if(a<=7&&b>=7)
            cout<<7<<endl;
    }
    if(w1<=2&&w2>=2)
    {
        if(a<=11&&b>=11)
            cout<<11<<endl;
    }
    if(w2>=3)
    {
        for(i=1; i<=9; i+=2)
        {
            for(j=0; j<=9; j++)
            {
                temp=i*100+i+j*10;
                if(temp>b)
                {
                    return 0;
                }
                else if(temp<a) continue;
                else if(isprime(temp))
                    cout<<temp<<endl;
            }
        }
    }
    if(w2>=5)
    {
        for(i=1;i<=9;i+=2)
        {
            for(j=0;j<=9;j++)
            {
                for(k=0;k<=9;k++)
                {
                    temp=i*10000+j*1000+k*100+j*10+i;
                    if(temp>b)
                        return 0;
                    else if(temp<a) continue;
                    else if(isprime(temp))
                        cout<<temp<<endl;
                }
            }
        }
    }
    if(w2>=7)
    {
        for(i=1;i<=9;i+=2)
        {
            for(j=0;j<=9;j++)
            {
                for(k=0;k<=9;k++)
                {
                    for(l=0;l<=9;l++)
                    {
                        temp=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
                        if(temp>b)
                            return 0;
                        else if(temp<a) continue;
                        else if(isprime(temp))
                            cout<<temp<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
int isprime(int n)
{
    int p=1;
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
int weishu(int n)
{
    int cnt=0;
    while(n>0)
    {
        n/=10;
        cnt++;
    }
    return cnt;
}
