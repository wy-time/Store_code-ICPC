#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    ll n;
    while(cin>>n)
    {
        ll sky=5;
        ll ground=11;
        ll begyear=2018;
        if(n>=begyear)
        {
            ll jiange=n-begyear;
            sky+=jiange%10;
            sky%=10;
            sky=sky==0?10:sky;
            ground+=jiange%12;
            ground%=12;
            ground=ground==0?12:ground;
            cout<<sky<<" "<<ground<<endl;
        }else
        {
            ll jiange=begyear-n;
            sky-=jiange%10;
            sky=sky<=0?sky+10:sky;
            ground-=jiange%12;
            ground=ground<=0?ground+12:ground;
            cout<<sky<<" "<<ground<<endl;
        }
    }
    return 0;
}
