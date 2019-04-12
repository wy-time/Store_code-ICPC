#include <iostream>
using namespace std;
int pre[10005];
int findx(int x);
void join(int a,int b);
int main ()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        pre[i]=i;
    for(i=0;i<m;i++)
    {
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1)
            join(x,y);
        else
        {
            int root=findx(x);
            if(root==findx(y))
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
int findx(int x)
{
    int t=x;
    while(t!=pre[t])
        t=pre[t];
    int i=x,j;
    while(pre[i]!=t)
    {
        j=pre[i];
        pre[i]=t;
        i=j;
    }
    return t;
}
void join(int a,int b)
{
    int a1=findx(a);
    int b1=findx(b);
    pre[b1]=a1;
}
