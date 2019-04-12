// #include<iostream>
// using namespace std;
// typedef struct
// {
//     int num;
//     int v;
//     int ip;
//     int type;
// } st;
// bool isbuy[100];
// int dp[70][33000];
// int vlual[100];
// int ip[100];
// int main ()
// {
//     st info [70];
//     int n,m;
//     cin>>n>>m;
//     n/=10;
//     int i;
//     //int cnt=1;
//     for(i=1; i<=m; i++)
//     {
//         cin>>info[i].v>>info[i].ip>>info[i].type;
//         info[i].v/=10;
//         if(info[i].type==0)
//         {
//             info[i].num=i;
//             vlual[i]=info[i].v;
//             ip[i]=info[i].ip;
//             //cnt++;
//         }
//         else
//             info[i].num=-1;
//     }
//     int j=0;
//     for(i=1; i<=m; i++)
//     {
//         for(j=n; j>=0; j--)
//         {
//             if(j>=info[i].v)
//             {
//                 if(info[i].type==0)
//                 {
//                     if(dp[i-1][j]<=dp[i-1][j-info[i].v]+(info[i].v*info[i].ip))
//                     {
//                         dp[i][j]=dp[i-1][j-info[i].v]+(info[i].v*info[i].ip);
//                         isbuy[info[i].num]=true;
//                     }
//                     else
//                         dp[i][j]=dp[i-1][j];
//                 }
//                 else
//                 {
//                     int temp=info[i].type;
//                     if(j-info[i].v-vlual[temp]>=vlual[temp+1]+vlual[temp]||(j-info[i].v-vlual[temp]>=vlual[temp]&&j-info[i].v-vlual[temp]<vlual[temp+1]))
//                     {
//                         if(isbuy[temp])
//                         {
//                             dp[i][j]=max(dp[i-1][j],dp[i-1][j-info[i].v-vlual[temp]]+info[i].v*info[i].ip);
//                         }else
//                         {
//                             if(dp[i-1][j]<=dp[i-1][j-info[i].v-vlual[temp]]+info[i].v*info[i].ip+vlual[temp]*ip[temp])
//                             {
//                                 dp[i][j]=dp[i-1][j-info[i].v-vlual[temp]]+info[i].v*info[i].ip+vlual[temp]*ip[temp];
//                                 isbuy[temp]=true;
//                             }else
//                             {
//                                 dp[i][j]=dp[i-1][j];
//                             }
//                         }
//                     }else
//                     {
//                         dp[i][j]=dp[i-1][j];
//                     }
//                 }
//             }else
//             {
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }
//     cout<<dp[m][n]*10;
//     return 0;
// }
#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
    int v; 0
    int cost;
    int cnt;
};
st info [65][3];
ll dp[35000];
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    int i, j;
    wfor(i, 0, m)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t3 == 0)
        {
            info[i][0].cost = t1;
            info[i][0].v = t1 * t2;
            info[i][0].cnt = 1;
        } else
        {
            int cnt = info[t3 - 1][0].cnt;
            info[t3 - 1][cnt].cost = t1;
            info[t3 - 1][cnt].v = t1 * t2;
            info[t3 - 1][0].cnt++;
        }
    }
    wfor(i, 0, m)
    {
        if (info[i][0].cnt == 0)
            continue;
        mfor(j, n, info[i][0].cost)
        {
            dp[j] = max(dp[j], dp[j - info[i][0].cost] + info[i][0].v);
            if (j >= info[i][0].cost + info[i][1].cost)
            {
                dp[j] = max(dp[j], dp[j - info[i][0].cost - info[i][1].cost] + info[i][0].v + info[i][1].v);
            }
            if (j >= info[i][0].cost + info[i][2].cost)
            {
                dp[j] = max(dp[j], dp[j - info[i][0].cost - info[i][2].cost] + info[i][0].v + info[i][2].v);
            }
            if (j >= info[i][0].cost + info[i][1].cost + info[i][2].cost)
            {
                dp[j] = max(dp[j], dp[j - info[i][0].cost - info[i][1].cost - info[i][2].cost] + info[i][0].v + info[i][1].v + info[i][2].v);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
