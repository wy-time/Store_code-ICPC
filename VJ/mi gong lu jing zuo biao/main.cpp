#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
int bfs(int x,int y);
const int INF=100000;
int s[25][25];
int n,m;
typedef pair<int,int>P;
bool road[11][11]={false};
bool lukou[11][11]={false};
int main()
{
    freopen("F:\\Desktop\\question\\VJ\\input.txt","r",stdin);
    n=5,m=5;
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>s[i][j];
    }
    bfs(0,0);
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(road[i][j])
                cout<<"("<<i<<","<<" "<<j<<")"<<endl;
        }
    }
    return 0;
}
int bfs(int x,int y)
{
    queue <P> t;
    int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
    int r[45][45];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            r[i][j]=INF;
        }
    }
    t.push(P(x,y));
    r[x][y]=0;
    road[x][y]=true;
    while(t.size())
    {
        P p=t.front();
        t.pop();
        x=p.first;
        y=p.second;
        if(x==4&&y==4)
        {
            break;
        }
        int nx,ny;
        int cnt=0;
        for(i=0;i<4;i++)
        {
            nx=dx[i]+x;
            ny=dy[i]+y;
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&r[nx][ny]==INF&&s[nx][ny]==0)
            {
                cnt++;
                road[nx][ny]=true;
                r[nx][ny]=r[x][y]+1;
                t.push(P(nx,ny));
            }
        }
        if(cnt>1)
        {
            lukou[x][y]=true;
        }else if(cnt==0&&(x!=4||y!=4))
        {
            int t1=x;
            int t2=y;
            int safe=1;
            while(!lukou[t1][t2]&&safe)
            {
                safe=0;
                int q,w;
                road[t1][t2]=false;
                for(i=0;i<4;i++)
                {
                    q=t1+dx[i];
                    w=t2+dy[i];
                    if(q>=0&&w>=0&&q<n&&w<n&&road[q][w])
                    {
                        t1=q;
                        t2=w;
                        safe=1;
                        break;
                    }
                }
            }
        }
    }
    return r[x][y];
}
