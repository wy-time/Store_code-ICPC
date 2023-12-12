#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }

int minimumSum(vector<int>& nums);
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
    vector<int> nums;
    int num;
    while (cin>>num)
    {
        nums.push_back(num);
    }
    cout<<minimumSum(nums)<<endl;
    return 0;
}
int minnums[100000][2];
int minimumSum(vector<int>& nums) {
    memset(minnums, 0, sizeof(int) * 100);
    int length = nums.size();
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            minnums[i][0] = 0x7f7f7f7f;
        } else {
            int minnum = min(nums[i - 1], minnums[i - 1][0]);
            if (minnum < nums[i]) {
                minnums[i][0] = minnum;
            } else {
                minnums[i][0] = 0x7f7f7f7f;
            }
        }
    }
    for (int i = length - 1; i >= 0 ; i--) {
        if (i == length - 1) {
            minnums[i][1] = 0x7f7f7f7f;
        } else {
            int minnum = min(nums[i + 1], minnums[i + 1][1]);
            if (minnum < nums[i]) {
                minnums[i][1] = minnum;
            } else {
                minnums[i][1] = 0x7f7f7f7f;
            }
        }
    }
    int res = 0x7f7f7f7f;
    for (int i = 1; i < length - 1 ; i++) {
        if (minnums[i][0] != 0x7f7f7f7f && minnums[i][1] != 0x7f7f7f7f) {
            res = min(minnums[i][1] + minnums[i][0] + nums[i],res);
        }
    }
    if (res == 0x7f7f7f7f) {
        res = -1;
    }
    return res;
}