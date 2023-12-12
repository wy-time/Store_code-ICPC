#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
vector<int> singleNumber(vector<int>& nums);

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
    int num;
    vector<int> nums;
    while (cin>>num)
    {
        nums.push_back(num);
    }
    auto res = singleNumber(nums);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
vector<int> singleNumber(vector<int>& nums) {
    ll res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }
    ll last = res & -res;
    vector<int> one;
    vector<int> zero;
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i]&last) == 0){
            zero.push_back(nums[i]);
        } else {
            one.push_back(nums[i]);
        }
    }
    ll res1 = one[0];
    ll res2 = zero[0];
    for (int i = 1; i < one.size(); i++) {
        res1 ^= one[i];
    }

    for (int i = 1; i < zero.size(); i++) {
        res2 ^= zero[i];
    }
    vector<int> result;
    result.push_back(res1);
    result.push_back(res2);
    return result;
}