#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }

long long maxKelements(vector<int>& nums, int k);
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
    int k;
    cin>>k;
    int num;
    while (cin>>num)
    {
        nums.push_back(num);
    }
    cout<<maxKelements(nums,k)<<endl;
    return 0;
}

long long maxKelements(vector<int>& nums, int k) {
    long long res = 0;
    priority_queue<int, vector<int>, less<int> >sort_nums;
    for (int i = 0; i < nums.size(); i++) {
        sort_nums.push(nums[i]);
    }

    for (int i = 0; i < k; i++) {
        long long top = sort_nums.top();
        res += top;
        sort_nums.pop();
        sort_nums.push(ceil(top / 3.0));
    }
    return res;
}