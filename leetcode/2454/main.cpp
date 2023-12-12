#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
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

// void build(TreeNode * root, int i, vector<int> &edge) {
//     root->val = edge[i];
//     if(i*2+1<edge.size() && edge[i*2+1] != -1) {
//         root->left = new TreeNode();
//         build(root->left,i*2+1,edge);
//     }

//     if(i*2+2<edge.size() && edge[i*2+2] != -1) {
//         root->right = new TreeNode();
//         build(root->right,i*2+2,edge);
//     }
// }
vector<int> secondGreaterElement(vector<int>& nums) {
    stack<pair<int,int>> st;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > qu;
    int n = nums.size();
    vector<int> ans = vector<int>(n,-1);
    for(int i=0;i<n;i++) {
        while (!qu.empty())
        {
            auto front = qu.top();
            if(nums[i] > front.first) {
                ans[front.second] = nums[i];
                qu.pop();
            } else {
                break;
            }
        }
        
        while(!st.empty() && nums[i] > st.top().first) {
            qu.push(st.top());
            st.pop();
        }
        st.push(pair<int,int>{nums[i],i});
    }
    return ans;
}
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
    vector<int> nums;
    cin>>n;
    int num;
    int i;
    for(i = 0; i<n;i++)
    {
        cin>>num;
        nums.push_back(num);
    }
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

    // vector<vector<int>>cost = {{1,5},{5,6},{6,7},{0,1},{1,2},{2,3},{3,4}};
    // vector<vector<int>>inputEdges = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    // vector<vector<int>>inputEdges = {{1,0},{1,2},{3,2},{3,4}};
    // vector<vector<int>>inputEdges = {{1,2,2},{3,8,2},{5,3,5}};
    // vector<vector<int>>inputEdges = {{1}};
    // vector<vector<int>>trips = {{0,3},{2,1},{2,3}};
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    nums = vector<int> {272,238,996,406,763,164,102,948,217,760,609,700,848,637,748,718,469,449,502,703,292,86,91,551,699,293,244,406,22,968,434,805,910,927,623,79,108,541,411};
    auto ans = secondGreaterElement(nums);
    auto ans2 = secondGreaterElement(nums);
    auto ans3 = secondGreaterElement(nums);
    auto ans4 = secondGreaterElement(nums);
    n = nums.size();
    wfor(i,0,n) {
        cout<<ans4[i]<<" ";
    }
    return 0;
}
