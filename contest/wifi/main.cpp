#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int result[5005]={0};
    int up=0,down=999999999;
    int i;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        if(l<down)
        {
            down=l;
        }
        if(r>up)
        {
            up=r;
        }
        for(i=l;i<=r;i++)
        {
            result[i]++;
        }
    }
    sort(result+down,result+1+up);
    int t=result[up];
    int r=t/m;
    if(t%m)
        r++;
    cout<<r;
    return 0;
}
