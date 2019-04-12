#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long c1,c2,c3,c4,v;
        cin>>c1>>c2>>c3>>c4>>v;
        long long sum=c2*5+c3*10+c4*50;
        int x=0;
        long long temp=((v/5)+1)*5;
        if(v%5==0)
            temp=v;
        else
            temp=((v/5)+1)*5;
        x=temp-v;
        c1+=(sum/temp)*x;
        cout<<c1<<endl;
    }
    return 0;
}
