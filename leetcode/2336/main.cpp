#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
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
class SmallestInfiniteSet {
public:
    set<int> st;
    int now;
    SmallestInfiniteSet() {
        st.clear();
        now = 1;
    }
    
    int popSmallest() {
        if(!st.empty()) {
            int val = *st.begin();
            st.erase(st.begin());
            return val;
        }
        return now++;
    }
    
    void addBack(int num) {
        if(num < now) {
            st.insert(num);
        }
    }
};
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
    auto queue = new FrontMiddleBackQueue();

    queue->pushMiddle(2);
    queue->pushMiddle(9);
    cout<<queue->popMiddle();
    queue->pushMiddle(6);
    queue->pushMiddle(6);
    queue->pushMiddle(5);
    cout<<queue->popMiddle();
    cout<<queue->popMiddle();
    queue->pushMiddle(6);
    // queue->pushMiddle(1);
    // queue->pushMiddle(10);
    // cout<<queue->popFront();
    // queue->pushBack(1);
    // queue->pushBack(2);
    // queue->pushBack(3);
    // queue->pushBack(4);
    // queue->popMiddle();
    return 0;
}
