#include <iostream>
using namespace std;
char ma[55][55];
void dfs (int x,int y);
int cnt;
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnttt=0;
    while(t--)
    {
        cnttt++;
        int sum=0;
        cin>>n;
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>ma[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ma[i][j]=='#')
                {
                    cnt=0;
                    dfs(i,j);
                    sum+=cnt/2;
                }
            }
        }
        cout<<"Case"<<" "<<cnttt<<":"<<" "<<sum<<endl;
    }
    return 0;
}
void dfs (int x,int y)
{
    ma[x][y]='.';
    cnt++;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int i;
    for(i=0;i<n;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0&&y1>=0&&x1<n&&y1<n&&ma[x1][y1]!='.')
        {
            dfs(x1,y1);
        }
    }
}
