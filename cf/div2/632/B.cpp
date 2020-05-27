#include <iostream>
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
const int maxn=1e5+5;
int a[maxn];
int b[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        int first_negative=-1;
        int first_postive=-1;
        wfor(i,0,n)
        {
            cin>>a[i];
            if (first_negative==-1&&a[i]==-1)
                first_negative=i;
            if(first_postive==-1&&a[i]==1)
                first_postive=i;
        }
        wfor(i,0,n)
        {
            cin>>b[i];
        }
        int flag=1;
        mfor(i,n-1,0)
        {
            if(a[i]!=b[i])
            {
                if(a[i]<b[i]&&(first_postive>=i||first_postive==-1))
                {
                    flag=0;
                    break;
                }
                if(a[i]>b[i]&&(first_negative>=i||first_negative==-1))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
