#include <iostream>
using namespace std;
char ma [105][105];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>ma[i][j];
        }
    }
    int x,y,k;
    char s;
    int face=0;
    cin>>x>>y>>s>>k;
    int dx[4]= {-1,0,1,0};
    int dy[4]= {0,1,0,-1};
    switch (s)
    {
        case 'U':
            face=0;
            break;
        case 'R':
            face=1;
            break;
        case 'D':
            face=2;
            break;
        case 'L':
            face=3;
            break;
    }
    while(k--)
    {
        if(ma[x][y]=='0')
        {
            face-=1;
            if(face<0)
                face=3;
            ma[x][y]='1';
            x+=dx[face];
            y+=dy[face];
        }else
        {
            ma[x][y]='0';
            face++;
            face%=4;
            x+=dx[face];
            y+=dy[face];
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
