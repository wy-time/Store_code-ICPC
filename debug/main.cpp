#include <iostream>
#include <algorithm> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
freopen("/home/time/debug/debug/in","r",stdin);
freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int num[6]={4,8,15,16,23,42};
    int t[4]={0};
    int i;
    wfor(i,1,5)
    {
        cout<<"? "<<1<<" "<<i+1<<endl;
        cin>>t[i-1];
    }
    do
    {
        int flag=1;
        wfor(i,0,4)
        {
            if(num[0]*num[i+1]!=t[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"! ";
            wfor(i,0,6)
                cout<<num[i]<<" ";
            cout<<endl;
            break;
        }
    }while(next_permutation(num,num+6));
    return 0;
}
