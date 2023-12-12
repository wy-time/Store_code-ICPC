#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
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

long long minSum(vector<int>& nums1, vector<int>& nums2);
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
    vector<int> nums1;
    vector<int> nums2;
    int num;
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>num;
        nums1.push_back(num);
    }
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>num;
        nums2.push_back(num);
    }
    cout<<minSum(nums1,nums2)<<endl;
    return 0;
}
long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0;
    long long sum2 = 0;
    int zero1 = 0;
    int zero2 = 0;
    for (auto it = nums1.begin(); it!=nums1.end();it++) {
        sum1 += *it;
        if (!*it) {zero1++;}
    }
    for (auto it = nums2.begin(); it!=nums2.end();it++) {
        sum2 += *it;
        if (!*it) {zero2++;}
    }
    if (zero1 != 0 && zero2 != 0) {
        sum1+=zero1;
        sum2+=zero2;
        return max(sum1,sum2);
    } else if(zero1 == 0 && zero2 == 0) {
        return sum1 == sum2 ? sum1 : -1;
    } else {
        if (zero1 == 0) {
            return sum2 + zero2 <= sum1 ? max(sum1,sum2 + zero2) : -1;
        } else {
            return sum1 + zero1 <= sum2 ? max(sum1 + zero1, sum2) : -1;
        }
    }
}
