#include <iostream>
#include <string> 
#include <map> 
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
map<string,pair<int,int> >peo;
string name[15];
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        string s;
        cin>>s;
        name[i]=s;
        peo.insert(make_pair(s,make_pair(0,0)));
    }
    string s;
    while(cin>>s)
    {
        int have;
        int num;
        cin>>have>>num;
        if(num==0)
            continue;
        peo[s].first+=have/num*num;
        wfor(i,0,num)
        {
            string temp;
            cin>>temp;
            peo[temp].second+=have/num;
        }
    }
    wfor(i,0,n)
        cout<<name[i]<<" "<<peo[name[i]].second-peo[name[i]].first<<endl;
    return 0;
}
