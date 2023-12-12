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
class NumArray {
public:
    vector<int> tree;
    vector<int>& nums;
    int size = 0;
    int lowbit(int k) {
        return k & -k;
    }

    int getsum(int x) {  // a[1]..a[x]的和
        int ans = 0;
        while (x > 0) {
            ans = ans + tree[x];
            x = x - lowbit(x);
        }
        return ans;
    }
    NumArray(vector<int>& nums):nums(nums) {
        size = nums.size();
        tree = vector<int>(size + 1, 0);
        // memset(&tree,0,sizeof(int) * tree.size());
        for(int i=1;i<=size;i++) {
            tree[i] += nums[i-1];
            int j = i + lowbit(i);
            if (j<=size){
                tree[j] += tree[i];
            }
        }
    }
    
    void update(int index, int val) {
        int idx = index + 1;
        while(idx <= size) {
            tree[idx] += (val - nums[index]);
            idx = idx + lowbit(idx);
        }
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return getsum(right + 1) - getsum(left);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\Desktop\question\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    // freopen("./in","r",stdin);
    // freopen("./out","w",stdout);
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
    int n;
    cin>>n;
    vector<int> nums;
    int i;
    wfor(i,0,n) {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    NumArray * na = new NumArray(nums);
    string s;
    while(cin>>s) {
        if (s == "update") {
            int index;
            int val;
            cin>>index>>val;
            na->update(index,val);
        } else {
            int left,right;
            cin>>left>>right;
            cout<<na->sumRange(left,right)<<endl;
        }
    }
    return 0;
}
