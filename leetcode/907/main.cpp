#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int sumSubarrayMins(vector<int>& arr) {
    stack<pair<int,int>> st;
    int mod = 1e9+7;
    int ans = 0;
    for(int i=0;i<arr.size();i++) {
        if(st.empty()) {
            st.push(make_pair(arr[i],i));
        } else {
            if(st.top().first>=arr[i]) {
                int cnt = 0;
                while (!st.empty() && st.top().first >= arr[i])
                {
                    auto top = st.top();
                    long long l = 0;
                    long long r = i - top.second - 1;
                    st.pop();
                    if (!st.empty()) {
                        auto sec = st.top();
                        l = top.second - sec.second - 1;
                    } else {
                        l = top.second;
                    }
                    ans = (ans + ((l + 1) * (r + 1) * top.first) % mod) % mod;
                }
                st.push(make_pair(arr[i],i));
            } else {
                st.push(make_pair(arr[i],i));
            }
        }
    }
    
    while (!st.empty()) {
        auto top = st.top();
        int l = 0;
        int r = arr.size() - top.second - 1;
        st.pop();
        if (!st.empty()) {
            auto sec = st.top();
            l = top.second - sec.second - 1;
        } else {
            l = top.second;
        }
        ans = (ans + ((l + 1) * (r + 1) * top.first) % mod) % mod;
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
    int n;
    cin>>n;
    int i;
    vector<int>nums;
    wfor(i,0,n) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    cout<<sumSubarrayMins(nums)<<endl;
    return 0;
}
