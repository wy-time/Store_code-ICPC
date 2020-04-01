#include <iostream>
#include <cctype> 
#include <set> 
#include <vector> 
#include <string> 
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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    cout<<"请输入产生式的的个数,格式为左部空格右部"<<endl;;
    int n;
    cin>>n;
    string s1,s2;
    int i;
    vector <string> S;
    set<string> Vn;
    set<char> Vt;
    vector<string>P;
    vector<string>temp;
    if(n!=0)
    {
        wfor(i,0,n)
        {
            cin>>s1>>s2;
            P.push_back(s1+"->"+s2);
            if(i==0)
                S.push_back(s1);
            Vn.insert(s1);
            temp.push_back(s2);
        }
        int sz=temp.size();
        wfor(i,0,sz)
        {
            int j;
            wfor(j,0,temp[i].length())
            {
                string t="";
                t+=temp[i][j];
                if(Vn.count(t)==0)
                    Vt.insert(temp[i][j]);
            }
        }
        cout<<"S:"<<S[0]<<endl;
        cout<<"Vt:";
        for(auto k:Vt)
            cout<<k<<" ";
        cout<<endl;
        cout<<"Vn:";
        for(auto k:Vn)
            cout<<k<<" ";
        cout<<endl;
        cout<<"P:";
        for (auto k:P)
            cout<<k<<endl;
    }
    return 0;
}
