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

int minGroupsForValidAssignment(vector<int>& nums);
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
    cout<<minGroupsForValidAssignment(nums)<<endl;
    return 0;
}
bool check(unordered_map<int,int>& numMap,int n) {
    if (n == 1) {
        return true;
    }
    for (auto i = numMap.begin(); i != numMap.end(); i++) {
        if (i->second / n < i->second % n) {
            return false;
        }
    }
    return true;
}
// int halfSearch(int left, int right) {
//     if (left + 1 >= right) {
//         return check(right) ? right : left;
//     }
//     int half = (right + left) / 2 ;
//     if (check(half)) {
//         return halfSearch(half , right);
//     } else {
//         return halfSearch(left, half);
//     }
// }
int minGroupsForValidAssignment(vector<int>& nums) {
    int minNum = 0x7f7f7f7f;
    unordered_map<int,int>numMap;
    for (int i = 0;i<nums.size();i++){
        if (numMap.find(nums[i])== numMap.end()) {
            numMap.insert(make_pair(nums[i],1));
        } else {
            numMap[nums[i]]++;
        }
    }
    for (auto i = numMap.begin(); i != numMap.end(); i++) {
        minNum = min(minNum, (*i).second);
    }
    int maxN = 1;
    for (int i = 1; i <= minNum; i++) {
        if (check(numMap,i)) {
            maxN = max(maxN, i);
        }
    }
    int sum = 0;
    for (auto i = numMap.begin(); i != numMap.end(); i++) {
        int x = i->second / maxN;
        sum += (i->second % maxN);
        x -= (i->second % maxN);
        x -= x / (maxN + 1);
        sum += x;
    }
    return sum;
}