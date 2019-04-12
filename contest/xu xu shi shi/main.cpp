#include <iostream>
#include<cstring>
using namespace std;
int ma[200];
int pre[200];
int findx(int a);
void join (int a,int b);
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int i;
        int n,m;
        cin>>n>>m;
        memset(ma,0,sizeof(ma));
        for(i=1;i<=n;i++)
            pre[i]=i;
        for(i=0;i<m;i++)
        {
            int b,c;
            cin>>b>>c;
            join(b,c);
            ma[b]++;
            ma[c]++;
        }
        int root=findx(1);
        bool liantong=true;
        for(i=2;i<=n;i++)
        {
            if(findx(i)!=root)
            {
                liantong=false;
                break;
            }
        }
        int jidian_cnt=0;
        if(!liantong)
        {
            cout<<"Xun"<<endl;
        }else
        {
            for(i=1;i<=n;i++)
            {
                if(ma[i]%2!=0)
                    jidian_cnt++;
            }
            if(jidian_cnt==0||jidian_cnt==2)
            {
                cout<<"Zhen"<<endl;
            }else
                cout<<"Xun"<<endl;
        }
    }
    return 0;
}
int findx(int x)
{
    int t=x;
    while(t!=pre[t])
    {
        t=pre[t];
    }
    int i=x,j;
    while(i!=t)
    {
        j=pre[i];
        pre[i]=t;
        i=j;
    }
    return t;
}
void join (int a,int b)
{
    int a1=findx(a);
    int b1=findx(b);
    pre[b1]=a1;
}
