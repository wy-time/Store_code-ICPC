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
int minDeletion(vector<int>& nums) {
    int last = -1;
    int ans = 0;
    for(int i=0;i<nums.size();i++) {
        if(last == -1) {
            last = nums[i];
        } else {
            if (nums[i] == last ) {
                ans++;
            } else {
                last = -1;
            }
        }
    }
    if ((nums.size() - ans) % 2 != 0) {
        ans++;
    }
    return ans;
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
    int n,k;
    cin>>n;
    int i;
    vector<int>nums;
    wfor(i,0,n) {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    cin>>k;
    cout<<longestAlternatingSubarray(nums,k)<<endl;
    return 0;
}
