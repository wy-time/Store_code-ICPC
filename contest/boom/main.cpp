#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ma[105][105];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(ma,0,sizeof(ma));
        int n;
        cin>>n;
        while(n--)
        {
            int x1[2];
            int y1[2];
            cin>>x1[0]>>y1[0]>>x1[1]>>y1[1];
            for(int i=x1[0];i<x1[1];i++)
                for(int j=y1[0];j<y1[1];j++)
                    ma[i][j]++;
        }
        int temp=1;
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                if(ma[i][j]>temp)
                    temp=ma[i][j];
        cout<<temp<<endl;
    }
    return 0;
}
