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

int vowelStrings(vector<string>& words, int left, int right);
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
    int left,right;
    cin>>left>>right;
    cout<<vowelStrings(words,left,right)<<endl;
    return 0;
}
int vowelStrings(vector<string>& words, int left, int right) {
    int res = 0;
    auto check = [](char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    };
    for(int i = left; i <= right; i++) {
        auto l = *(words[i].begin());
        auto r = *(words[i].rbegin());
        if (check(l) && check(r)){
            res++;
        }
    }
    return res;
}