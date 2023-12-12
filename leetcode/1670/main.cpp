#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
class FrontMiddleBackQueue {
public:
    list<int> li;
    list<int>::iterator mid_push;
    list<int>::iterator mid_erase;
    FrontMiddleBackQueue() {
        li.clear();
        mid_push = li.begin();
        mid_erase = li.begin();
    }
    
    void pushFront(int val) {
        li.push_front(val);
        if(li.size() == 1) {
            mid_push = li.begin();
            mid_erase = li.begin();
        } else {
            if(li.size() % 2 == 0) {
                mid_erase--;
            } else {
                mid_push--;
            }
        }
        // cout<<"push"<<*mid_push<<endl;
        // cout<<"erase"<<*mid_erase<<endl;
    }
    
    void pushMiddle(int val) {
        if(li.empty()) {
            li.push_back(val);
            mid_push = li.begin();
            mid_erase = li.begin();
        } else {
            auto it = li.insert(mid_push, val);
            mid_erase = it;
            if(li.size() % 2 == 0) {
                mid_push = ++it;
            } else {
                mid_push = it;
            }
        }
        
        // cout<<"push"<<*mid_push<<endl;
        // cout<<"erase"<<*mid_erase<<endl;
    }
    
    void pushBack(int val) {
        li.push_back(val);
        if(li.size() == 1) {
            mid_push = li.begin();
            mid_erase = li.begin();
        } else {
            if(li.size() % 2 == 0) {
                mid_push++;
            } else {
                mid_erase++;
            }
        }
        // cout<<"push"<<*mid_push<<endl;
        // cout<<"erase"<<*mid_erase<<endl;
    }
    
    int popFront() {
        if(li.empty()) {
            return -1;
        }
        if(li.size() % 2 != 0) {
            ++mid_push;
        } else {
            ++mid_erase;
        }
        int val = li.front();
        li.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(li.empty()) {
            return -1;
        }
        int val = *mid_erase;
        auto it = li.erase(mid_erase);
        mid_push = it;
        if(li.empty()) {
            return val;
        }
        if(li.size() % 2 == 0) {
            mid_erase = --it;
        } else {
            mid_erase = it;
        }
        // cout<<"push"<<*mid_push<<endl;
        // cout<<"erase"<<*mid_erase<<endl;
        return val;
    }
    
    int popBack() {
        if(li.empty()) {
            return -1;
        }
        if(li.size() % 2 != 0) {
            --mid_erase;
        } else {
            --mid_push;
        }
        int val = li.back();
        li.pop_back();
        return val;
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
