#include <iostream>
#include<string>
using namespace std;
string map1[1005];
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>map1[i];
    }
    while(q--)
    {
        int x,y;
        char r;
        cin>>x>>y>>r;
        int p=1;
        if(r=='R')
        {
            for(j=y-1;j<m;j++)
            {
                if(map1[x-1][j]!='*')
                {
                    p=0;
                    break;
                }
            }
        }else if(r=='L')
        {
            for(j=y-1;j>=0;j--)
            {
                if(map1[x-1][j]!='*')
                {
                    p=0;
                    break;
                }
            }
        }else if(r=='U')
        {
            for(i=x-1;i>=0;i--)
            {
                if(map1[i][y-1]!='*')
                {
                    p=0;
                    break;
                }
            }
        }else if(r=='D')
        {
            for(i=x-1;i<n;i++)
            {
                if(map1[i][y-1]!='*')
                {
                    p=0;
                    break;
                }
            }
        }
        if(p)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
