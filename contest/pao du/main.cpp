#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int jiu=a*6;
        int i;
        int hp=100;
        int flag=1;
        for(i=0;i<=b;i++)
        {
            if(((hp>jiu&&hp-a<=jiu))&&c!=0)
            {
                hp=80;
                c--;
            }else
                hp-=a;
            if(hp<=0)
            {
                flag=0;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
