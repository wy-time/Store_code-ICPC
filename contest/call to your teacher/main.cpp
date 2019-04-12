#include <iostream>
using namespace std;
int pre[1000];
int findx(int x);
void join(int x,int y);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        int i;
        for(i=0; i<=n; i++)
        {
            pre[i]=i;
        }
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if(b!=1)
                join(a,b);
        }
        if(findx(n)==findx(1))
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
int findx(int x)
{
    int temp=x;
    while(pre[temp]!=temp)
    {
        temp=pre[temp];
    }
    int i=x, j ;
    while( i != temp )
    {

        j = pre[ i ];

        pre[ i ]= temp ;

        i=j;

    }
    return temp;
}
void join(int x,int y)
{
    int t1=findx(x);
    int t2=findx(y);
    if(t1!=t2)
    {
        pre[t2]=t1;
    }
}
