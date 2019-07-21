#include <iostream>
#include <queue> 
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
const int maxn=1005;
int num[maxn];
struct st
{
    int val;
    int id;
    int peop;
    st(){}
    st(int a,int b,int c){
        val=a;
        id=b;
        peop=c;
    }
    bool operator <(const st &b)const
    {
        return val>b.val;
    }
};
int ans[maxn];
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
    int n,m;
    while(cin>>n>>m)
    {
        priority_queue<st>qu;
        int i;
        wfor(i,0,n)
        {
            cin>>num[i];
            qu.push(st(0,i,0));
        }
        while(m)
        {
            st temp=qu.top();
            qu.pop();
            temp.val+=num[temp.id];
            temp.peop++;
            qu.push(temp);
            m--;
        }
        int flag=1;
        int last=qu.top().val;
        ans[qu.top().id]=qu.top().peop;
        qu.pop();
        while(!qu.empty())
        {
            ans[qu.top().id]=qu.top().peop;
            int temp=qu.top().val;
            qu.pop();
            if(temp!=last)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<"Yes"<<endl;
            wfor(i,0,n-1)
            {
                cout<<ans[i]<<" ";
            }
            cout<<ans[i]<<endl;
        }else
            cout<<"No"<<endl;
    }
    
    return 0;
}
