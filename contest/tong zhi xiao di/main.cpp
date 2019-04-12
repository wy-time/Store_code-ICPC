#include <iostream>
using namespace std;
int pre [505];
bool ans[505];
int findx(int x);
bool join(int x,int y);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        int a[505];
        int cnt=0;
        for(i=0; i<=n; i++)
        {
            pre[i]=i;
        }
        int temp=m;
        int i=0;
        while(temp--)
        {
            cin>>a[i];
            pre[a[i]]=0;
            cnt++;
            i++;
        }
        temp=m;
        int result
        while(temp--)
        {
            i=0;
            int t;
            cin>>t;
            while(t--)
            {
                int temp;
                cin>>temp;
                if(join(a[i],temp))
                    cnt++;
            }
        }
        if(cnt==n)
            cout
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
bool join(int x,int y)
{
    int t1=findx(x);
    int t2=findx(y);
    if(t1!=t2)
    {
        pre[t2]=t1;
        return true;
    }else
        return false;
}
