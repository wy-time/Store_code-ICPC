#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }

int findTheLongestBalancedSubstring(string s);
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\Desktop\question\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    // int n;
    // vector<string> words;
    // cin>>n;
    // string word;
    // for(int i = 0; i<n;i++)
    // {
    //     cin>>word;
    //     words.push_back(word);
    // }
    string s;
    cin>>s;
    cout<<findTheLongestBalancedSubstring(s)<<endl;
    return 0;
}
int findTheLongestBalancedSubstring(string s) {
    int len = s.size();
    int one = s[0] == '1';
    int zero = s[0] == '0';
    int res = 0;
    for(int i = 1;i<len;i++) {
        if(s[i-1] == '0' && s[i] == '0') {
            zero++;
        } else if (s[i-1] == '0' && s[i] == '1') {
            one++;
            res = max(res,min(zero,one) * 2);
        } else if(s[i-1] =='1' && s[i] == '1') {
            one++;
            res = max(res,min(zero,one) * 2);
        } else {
            zero = 1;
            one = 0;
        }
    }
    return res;
}