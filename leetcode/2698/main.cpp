#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }

int punishmentNumber(int n);
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
    // vector<int> nums;
    // int num;
    // while (cin>>num)
    // {
    //     nums.push_back(num);
    // }
    for (int i = 1; i <= 1000; i++){
        cout<<punishmentNumber(i)<<endl;
    }
    return 0;
}
int punishmentNumber(int n) {
    int sum = 0;
    for(int i = 1; i<= n ;i++) {
        set<int,less<int> > dp[7];
        int signalNum[7];
        int nums[7][7];
        int squard = i * i;
        int idx = 6;
        while(squard > 0) {
            signalNum[idx] = squard % 10;
            squard /= 10;
            idx--;
        }
        idx++;
        for(int j = idx; j<7; j++) {
            int base = 0;
            for(int k = j; k<7; k++) {
                nums[j][k] = base * 10 + signalNum[k];
                base = nums[j][k];
            }
        }
        for(int k = idx; k<7; k++) {
            dp[k].insert(nums[idx][k]);
            int temp = k - 1;
            while (temp >= idx)
            {
                if(nums[temp+1][k] > i) { break; }
                for (auto num = dp[temp].begin(); num!=dp[temp].end(); num++){
                    if (*num + nums[temp+1][k] > i) { break; }
                    dp[k].insert(*num + nums[temp+1][k]);
                }
                temp--;
            }
        }
        
        if (dp[6].count(i) != 0 ){
            sum += i*i;
        }
    }
    return sum;
}