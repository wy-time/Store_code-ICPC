#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a,b,c;
    int t;
    cin>>t;
    bool flag[3]={true,true,true};
    while(t--)
    {
        int cnt=0;
        cin>>a>>b>>c;
        while(a>0&&b>0)
        {
            if(flag[0]&&c!=0)
            {
                cnt++;
                flag[0]=false;
                flag[1]=flag[2]=true;
                c--;
            }else if(flag[1]&&a<=b&&b>=2)
            {
                cnt++;
                flag[1]=false;
                flag[0]=flag[2]=true;
                a--;
                b-=2;
            }else if(flag[2]&&a>b&&a>=2)
            {
                cnt++;
                flag[2]=false;
                flag[0]=flag[1]=true;
                a-=2;
                b--;
            }
            if(a<2&&b<2&&c==0)
                break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
