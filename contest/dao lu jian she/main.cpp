#include <iostream>
#include<algorithm>
using namespace std;
int pre[105];
int findx(int x);
bool join(int x,int y);
bool ans[105];
typedef struct
{
    int a;
    int b;
    int h;
}st;
bool cmp(st a,st b)
{
    return a.h<b.h;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int c,n,m;
    st road[10005];
    while(cin>>c>>n>>m)
    {
        int i;
        int sum=0;
        for(i=0; i<=m; i++)
        {
            pre[i]=i;
        }
        for(i=0;i<n;i++)
            cin>>road[i].a>>road[i].b>>road[i].h;
        sort(road,road+n,cmp);
        for(i=0;i<n;i++)
        {
            if(join(road[i].a,road[i].b))
            {
                sum+=road[i].h;
            }
        }
        if(sum>c)
            cout<<"No"<<endl;
        else
        {
            bool right=true;;
            for(i=1;i<=m;i++)
            {
                int t=pre[1];
                if(pre[i]!=t)
                {
                    right=false;
                    break;
                }
            }
            if(right)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
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
