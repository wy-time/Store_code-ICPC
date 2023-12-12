#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int charCount1[200];
int charCount2[200];
unordered_map<int,int>countMap1;
unordered_map<int,int>countMap2;
bool closeStrings(string word1, string word2) {
    memset(charCount1,0,sizeof(int) * 200);
    memset(charCount2,0,sizeof(int) * 200);
    for(auto it = word1.begin(); it!= word1.end();it++) {
        charCount1[*it]++;
    }
    for(auto it = word2.begin(); it!= word2.end();it++) {
        charCount2[*it]++;
    }
    countMap1.clear();
    countMap2.clear();
    for(int i = 'a';i<='z';i++) {
        countMap1[charCount1[i]]++;
        countMap2[charCount2[i]]++;
    }
    for(int i = 'a';i<='z';i++) {
        if(charCount1[i] == charCount2[i]) {
            continue;
        }
        if(charCount1[i] == 0 || charCount2[i] == 0) {
            return false;
        }
        if(countMap1[charCount1[i]] != countMap2[charCount1[i]]) {
            return false;
        }
    }
    return true;
}
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
    // int n,m;
    // cin>>n>>m;
    // int i,j;
    // vector<vector<int>>grid;
    // wfor(i,0,n) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     grid.push_back(temp);
    // }

    // vector<vector<int>>cost;
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    string s1,s2;
    cin>>s1>>s2;
    cout<<closeStrings(s1,s2)<<endl;
    return 0;
}
