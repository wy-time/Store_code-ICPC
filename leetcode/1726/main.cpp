#include <iostream>
#include <vector>
#include <cstdio>
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

int tupleSameProduct(vector<int>& nums);
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
    cout<<tupleSameProduct(nums)<<endl;
    return 0;
}

long long fact(int n) {
    long long res = 1;
    for (long long i = 1; i <= n ; i++) {
        res *= i;
    }
    return res;
}

int tupleSameProduct(vector<int>& nums) {
    unordered_map<int,int> counts;
    for (int i = 0; i< nums.size(); i++) {
        for (int j = i + 1; j< nums.size(); j++) {
            int num = nums[i] * nums[j];
            if (counts.find(num) != counts.end()){
                counts[num]++;
            } else {
                counts.insert(make_pair(num,1));
            }
        }
    }
    long long res = 0;
    for(auto i = counts.begin(); i != counts.end(); i++) {
        int count = (*i).second;
        if (count >= 2) {
            res += fact(count) / (fact(count - 2) * 2);
        }
    }
    return res * 8;
}