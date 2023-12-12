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

int maxProduct(vector<string>& words);
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
    int n;
    vector<string> words;
    cin>>n;
    string word;
    for(int i = 0; i<n;i++)
    {
        cin>>word;
        words.push_back(word);
    }
    // int k;
    // cin>>k;
    cout<<maxProduct(words)<<endl;
    return 0;
}
int num[1000];
int maxProduct(vector<string>& words) {
    memset(num,0,sizeof(int) * 1000);
    int size = words.size();
    for(int j = 0; j < size; j++) {
        int len = words[j].length();
        for(int i = 0; i < len; i++) {
            num[j] |= (1<<(words[j][i] - 'a'));
        }
    }
    int res = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if ((num[i] & num[j]) == 0) {
                res = max(res, int(words[i].length() * words[j].length()));
            }
        }
    }
    return res;
}