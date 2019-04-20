#include <iostream>
#include <cstring> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1e5 + 5;
int num[maxn];
int sum1[4][maxn];
int main()
{
    // std::ios::sync_with_stdio(false);
    // #ifdef test
    // freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    // #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int t;
    // cin>>t;
    scanf("%d", &t);
    while (t--)
    {
        memset(sum1,0,sizeof(sum1));
        sum1[0][0]=sum1[1][0]=sum1[2][0]=sum1[3][0]=0;
        int n;
        scanf("%d", &n);
        // cin >> n;
        int i;
        wfor(i, 1, n + 1)
        {
            scanf("%d", &num[i]);
            // cin >> num[i];
        }
        sum1[0][1]=num[1];
        for(i=5;i<=n;i+=4)
        {
            sum1[0][i]^=sum1[0][i-4]^num[i];
        }
        sum1[1][2]=num[2];
        for(i=6;i<=n;i+=4)
        {
            sum1[1][i]^=sum1[1][i-4]^num[i];
        }
        sum1[2][3]=num[3];
        for(i=7;i<=n;i+=4)
        {
            sum1[2][i]^=sum1[2][i-4]^num[i];
        }
        sum1[3][4]=num[4];
        for(i=8;i<=n;i+=4)
        {
            sum1[3][i]^=sum1[3][i-4]^num[i];
        }
        int q;
        // cin >> q;
        scanf("%d", &q);
        while (q--)
        {
            ll ans = 0;
            int l, r;
            //cin >> l >> r;
            scanf("%d %d", &l, &r);
            int len = r - l + 1;
            if (len % 4 == 0)
            {
                ans = 0;
            } else if (len % 4 == 1)
            {
                int pos=l%4;
                if(pos==0)
                    pos=3;
                else
                    pos--;
                ans=sum1[pos][max(0,l-4)]^sum1[pos][(r-1-pos)/4*4+1+pos];
            } else if (len % 4 == 2)
            {
                int pos=l%4;
                if(pos==0)
                    pos=3;
                else
                    pos--;
                ans=sum1[pos][max(0,l-4)]^sum1[pos][(r-1-pos)/4*4+1+pos];
                pos=(l+1)%4;
                if(pos==0)
                    pos=3;
                else
                    pos--;
                ans^=sum1[pos][max(l-3,0)]^sum1[pos][(r-1-pos)/4*4+1+pos];
            } else
            {
                int pos=(l+1)%4;
                if(pos==0)
                    pos=3;
                else
                    pos--;
                ans=sum1[pos][max(0,l-3)]^sum1[pos][(r-1-pos)/4*4+1+pos];
            }
            // cout << ans << endl;
            printf("%lld\n", ans);
        }
        cout<<endl;
    }
    return 0;
}
