#include <iostream>
using namespace std;
long long cnt(int a,int b);
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        long long  result =cnt(a,b);
        cout<<result<<endl;;
    }
    return 0;
}
long long cnt(int a,int b)
{
    if(b-a==1)
    {
        return 1;
    }
    else if(b-a==2)
    {
        return 2;
    }
    else if(b-a==3)
    {
        return 3;
    }
    else if(b-a==4)
        return 5;
    else if(b-a==5)
        return 8;
    else if(b-a==6)
        return 13;
    else if(b-a==7)
        return 21;
    else if(b-a==8)
        return 34;
    else if(b-a==9)
        return 55;
    else if(b-a==10)
        return 89;
    else if(b-a==11)
        return 144;
    else if(b-a==12)
        return 233;
    else if(b-a==13)
        return 377;
    else if(b-a==14)
        return 610;
    else if(b-a==15)
        return 987;
    else if(b-a==16)
        return 1597;
    else if(b-a==17)
        return 2584;
    else if(b-a==18)
        return 4181;
    else if(b-a==19)
        return 6765;
    else if(b-a==20)
        return 10946;
    else
        return cnt(a,b-1)+cnt(a,b-2);
}
