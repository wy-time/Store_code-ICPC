#include <iostream>
using namespace std;
char ma[1005][6];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        int i,j;
        for(i=0; i<n; i++)
        {
            for(j=0; j<5; j++)
            {
                cin>>ma[i][j];
            }
        }
        bool is=false;
        for(i=0; i<n; i++)
        {
            if(ma[i][0]=='O'&&ma[i][1]=='O')
            {
                ma[i][0]='+';
                ma[i][1]='+';
                is=true;
                break;
            }
            else if(ma[i][3]=='O'&&ma[i][4]=='O')
            {
                ma[i][3]='+';
                ma[i][4]='+';
                is=true;
                break;
            }
        }
        if(is)
        {
            cout<<"YES"<<endl;
            for(i=0; i<n; i++)
            {
                for(j=0; j<5; j++)
                {
                    cout<<ma[i][j];
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
