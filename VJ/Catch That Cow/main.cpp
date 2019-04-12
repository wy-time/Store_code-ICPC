#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
int ans[300005];
const int INF=0xffffffff;
void bfs(int x,int y);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    memset(ans,0xff,sizeof(ans));
    bfs(n,k);
    cout<<ans[k]<<endl;
    return 0;
}
void bfs(int x,int y)
{
    int dd[2]= {1,-1};
    queue<int >qe;
    qe.push(x);
    ans[x]=0;
    int i;
    int flag=0;
    while(!qe.empty())
    {
        x=qe.front();
        qe.pop();
        for(i=0; i<3; i++)
        {
            int x1;
            if(i==2)
            {
                x1=x*2;
                if(x==0)
                    break;
            }
            else
            {
                x1=x+dd[i];
            }
            if(x1>=0&&x1<=2*y&&ans[x1]==INF)
            {
                ans[x1]=ans[x]+1;
                qe.push(x1);
                if(x1==y)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
}
