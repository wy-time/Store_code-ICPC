#include <iostream>
#include <fstream> 
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
int num[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    fstream _out;
    fstream _stdout;
    _out.open("out",ios::in);
    _stdout.open("stdout",ios::in);
    int flag=1;
    string s,s2;
    _out>>s;
    _stdout>>s2;
    if(s.compare(s2)!=0)
    {
        flag=0;
    }
    if(flag&&s=="YES"&&s2=="YES")
    {
        int n,m;
        cin>>n>>m;
        int i;
        wfor(i,1,n+1)
        {
            _out>>num[i];
        }
        wfor(i,0,m)
        {
            if(flag==0)
                break;
            int t,l,r;
            cin>>t>>l>>r;
            if(t==1)
            {
                int j;
                wfor(j,l+1,r+1)
                {
                    if(num[j]<num[j-1])
                    {
                        flag=0;
                        break;
                    }
                }
            }else
            {
                int j;
                int cnt=0;
                wfor(j,l+1,r+1)
                {
                    if(num[j]<num[j-1])
                    {
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0)
                {
                    flag=0;
                }
            }
        }
    }
    _out.close();
    _stdout.close();

    _out.open("out",ios::out|ios::trunc);
    _stdout.open("stdout",ios::out|ios::trunc);
    if(flag==0)
        _out<<"No"<<endl;
    else
        _out<<"OK"<<endl;
    _stdout<<"OK"<<endl;
    _out.close();
    _stdout.close();
    return 0;
}
