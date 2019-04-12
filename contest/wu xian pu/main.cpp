#include <iostream>
using namespace std;
char ma [10][5005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    char ans[9]={'F','E','D','C','B','A','G','F','E'};
    for(i=0;i<9;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ma[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(ma[j][i]=='|')
            {
                cout<<'|';
                break;
            }
            else
            {
                if(ma[j][i]=='o')
                {
                    cout<<ans[j];
                    break;
                }
            }
        }
    }
    return 0;
}
