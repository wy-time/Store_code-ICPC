#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
int bfs(int x,int y);
const int INF=100000;
char s[25][25];
int n,m;
typedef pair<int,int>P;
bool door[11]={false};
int main()
{
    freopen("F:\\Desktop\\question\\VJ\\input.txt","r",stdin);
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    bfs(0,0);
    for(i=0;i<10;i++)
        if(door[i])
            cout<<(char)(i+'A');
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
    while(t.size())
    {
        P p=t.front();
        t.pop();
        x=p.first;
        y=p.second;
        if(r[x][y]=='^')
        {
            break;
        }
        int nx,ny;
        for(i=0;i<4;i++)
        {
            nx=dx[i]+x;
            ny=dy[i]+y;
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&r[nx][ny]==INF&&s[nx][ny]!='*')
            {
                if(s[nx][ny]!='.')
                    if(s[nx][ny]>='A'&&s[nx][ny]<='Z')
                        //door[s[nx][ny]-'a']=true;
                    //else
                        door[s[nx][ny]-'A']=true;
                r[nx][ny]=r[x][y]+1;
                t.push(P(nx,ny));
            }
        }
    }
    return r[x][y];
}
