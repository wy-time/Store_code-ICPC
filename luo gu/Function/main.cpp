#include <iostream>
using namespace std;
long long w(long long a,long long b,long long c);
long long r[21][21][21];
int main()
{
    long long a,b,c;
    while(cin>>a>>b>>c&&(a!=-1||b!=-1||c!=-1))
    {
        long long t=w(a,b,c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<t<<endl;
    }
    return 0;
}
long long w(long long a,long long b,long long c)
{
    long long t;
    if(a<=0||b<=0||c<=0)
    {
        return 1;
    }
    if(a>20||b>20||c>20)
    {
        a=20;
        b=20;
        c=20;
    }
    if(r[a][b][c]==0)
    {
        if(a<b&&b<c)
        {
            t=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
            r[a][b][c]=t;
        }else
        {
            t=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
            r[a][b][c]=t;
        }
    }
    else
    {
        t=r[a][b][c];
    }
    return t;
}
