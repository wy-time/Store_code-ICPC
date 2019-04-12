#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    char ans [21][15]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"},{"twenty"}};
    int h,m;
    cin>>h>>m;
    if(h>20)
    {
        cout<<ans[20]<<" ";
        h%=20;
    }
    cout<<ans[h]<<" ";
    if(m)
    {
        if(m>20)
        {
            switch (m/10)
            {
                case 2:
                    cout<<"twenty"<<" ";
                    break;
                case 3:
                    cout<<"thirty"<<" ";
                    break;
                case 4:
                    cout<<"forty"<<" ";
                    break;
                case 5:
                    cout<<"fifty"<<" ";
            }
            m%=10;
        }
        cout<<ans[m];
    }else
        cout<<"o'clock";
    return 0;
}
